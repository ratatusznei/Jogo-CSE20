#include "Jogo.h"
#include<time.h>

Jogo::Jogo ():
_jogador1(&_inJ1, &_listaProjAmigos, 20, 50),
_jogador2(&_inJ2, &_listaProjAmigos, 680, 0)
{
	srand(clock());
	_faseAtual = NULL;

	_inJ1.SetKeyEsquerda(sf::Keyboard::A);
	_inJ1.SetKeyDireita(sf::Keyboard::D);
	_inJ1.SetKeyPulo(sf::Keyboard::W);
	_inJ1.SetKeyAtaque(sf::Keyboard::Space);

	_inJ2.SetKeyEsquerda(sf::Keyboard::Left);
	_inJ2.SetKeyDireita(sf::Keyboard::Right);
	_inJ2.SetKeyPulo(sf::Keyboard::Up);
	_inJ2.SetKeyAtaque(sf::Keyboard::RShift);

	_jogador1.IniciarDoctor();
	_jogador2.IniciarRobo();

	_colisoes.Incluir(&_jogador1);
	_colisoes.Incluir(&_jogador2);
	_colisoes.SetListaInimigos(&_listaInimigos);
	_colisoes.SetListaPlataformas(&_listaPlataformas);
	_colisoes.SetListaProjAmigos(&_listaProjAmigos);
	_colisoes.SetListaProjInimigos(&_listaProjInimigos);

	_texFundo.loadFromFile("res/sprites/egypt_backg.png");
	_spFundo.setTexture(_texFundo);
	_spFundo.setScale(2, 2);

	_cameraX = 0;
	_estaPausado = false;

    _fontePausado.loadFromFile(Resources::fonte_menu);
	_textoPausado.setFont(_fontePausado);
	_textoPausado.setString("PAUSE");
	_textoPausado.setOrigin(_textoPausado.getLocalBounds().width / 2, _textoPausado.getLocalBounds().height / 2);
}


Jogo::~Jogo () {
    if (_faseAtual != NULL) {
        delete _faseAtual;
    }
}

void Jogo::Executar () {
	if (_jogador1.GetMorreu() && (!_coop || _jogador2.GetMorreu())) {
		_acabou = true;
	}
	else if (_faseAtual->ChecarObjetivo()) {
        Fase* nova_fase = _faseAtual->CarregaProximaFase();
        delete _faseAtual;

        if (nova_fase != NULL) {
            _faseAtual = nova_fase;
        }
        else {
            _acabou = true;
        }
	}
	else if (!_estaPausado) {
		GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();
		float dt = janela->GetDeltaTime();

		_jogador1.Executar(dt);
		_jogador2.Executar(dt);

		if (!_listaInimigos.estaVazia()) {
			_listaInimigos.goToTop();
			do {
				Inimigo* pi = _listaInimigos.getWhatIsHere();

				pi->Executar(dt);

				if (pi->GetMorreu()) {
					_listaInimigos.removeWhatIsHere();
					--_listaInimigos;
				}
			} while(!(++_listaInimigos));
		}

		if (!_listaProjAmigos.estaVazia()) {
			_listaProjAmigos.goToTop();
			do {
				Projetil* pp = _listaProjAmigos.getWhatIsHere();

				pp->Executar(dt);

				if (pp->GetMorreu()) {
					_listaProjAmigos.removeWhatIsHere();
					--_listaProjAmigos;
				}
			} while(!(++_listaProjAmigos));
		}

		if (!_listaProjInimigos.estaVazia()) {
			_listaProjInimigos.goToTop();
			do {
				Projetil* pp = _listaProjInimigos.getWhatIsHere();

				pp->Executar(dt);

				if (pp->GetMorreu()) {
					_listaProjInimigos.removeWhatIsHere();
					--_listaProjInimigos;
				}
			} while(!(++_listaProjInimigos));
		}

		_colisoes.Calcular();
	}
}

void Jogo::Desenhar () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();
	float dt = janela->GetDeltaTime();

	int desejado_cameraX = 0;

	if (!_jogador1.GetMorreu()) {
			desejado_cameraX += _jogador1.GetPosicao().x;
	}

	if (_coop && !_jogador2.GetMorreu()) {
		desejado_cameraX += _jogador2.GetPosicao().x;

		if (!_jogador1.GetMorreu()) {
			desejado_cameraX /= 2;
		}
	}

	// Interpolacao linear da camera
	_cameraX = _cameraX + (desejado_cameraX - _cameraX) * dt / 0.2;
	janela->SetCamera(_cameraX);

	_spFundo.setPosition(_cameraX - Janela::meia_largura, 0);
	janela->Desenhar(_spFundo);

	if (!_jogador1.GetMorreu()) {
		_jogador1.Desenhar();
	}
	if (_coop && !_jogador2.GetMorreu()) {
		_jogador2.Desenhar();
	}

	if (!_listaPlataformas.estaVazia()) {
		_listaPlataformas.goToTop();
		do {
			_listaPlataformas.getWhatIsHere()->Desenhar();
		} while(!(++_listaPlataformas));
	}

	if (!_listaInimigos.estaVazia()) {
		_listaInimigos.goToTop();
		do {
			Inimigo* pi = _listaInimigos.getWhatIsHere();
			pi->Desenhar();
		} while(!(++_listaInimigos));
	}

	if (!_listaProjAmigos.estaVazia()) {
		_listaProjAmigos.goToTop();
		do {
			Projetil* pp = _listaProjAmigos.getWhatIsHere();
			pp->Desenhar();
		} while(!(++_listaProjAmigos));
	}

	if (!_listaProjInimigos.estaVazia()) {
		_listaProjInimigos.goToTop();
		do {
			Projetil* pp = _listaProjInimigos.getWhatIsHere();
			pp->Desenhar();
		} while(!(++_listaProjInimigos));
	}

	if (_estaPausado) {
        _textoPausado.setPosition(_cameraX, Janela::meia_altura);
        janela->Desenhar(_textoPausado);
	}
}

void Jogo::Iniciar(bool ehCoop) {
	_coop = ehCoop;
	_acabou = false;

	_jogador1.IniciarDoctor();
	_jogador2.IniciarRobo();

	if (_faseAtual != NULL) {
		delete _faseAtual;
		_faseAtual = NULL;
	}

	_faseAtual = new FaseEgito(&_jogador1, &_jogador2);
	CarregarFase(_faseAtual);
}

bool Jogo::GameOver () {
	return _acabou;
}

void Jogo::CarregarFase (Fase *pFase) {
	_listaPlataformas.mataLista();
	_listaInimigos.mataLista();

	pFase->CarregaJogadores();
	pFase->CarregaPlataformas(&_listaPlataformas);
	pFase->CarregaInimigos(&_listaInimigos, &_listaProjInimigos);
}

void Jogo::TogglePausa () {
    _estaPausado = !_estaPausado;
}
