#include "Jogo.h"
#include<time.h>

Jogo::Jogo ():
_jogador1(&_in_j1, &_listaProjAmigos, 20, 50),
_jogador2(&_in_j2, &_listaProjAmigos, 680, 0)
{
	srand(clock());
	_faseAtual = NULL;

	_in_j1.SetKeyEsquerda(sf::Keyboard::A);
	_in_j1.SetKeyDireita(sf::Keyboard::D);
	_in_j1.SetKeyPulo(sf::Keyboard::W);
	_in_j1.SetKeyAtaque(sf::Keyboard::Space);

	_in_j2.SetKeyEsquerda(sf::Keyboard::Left);
	_in_j2.SetKeyDireita(sf::Keyboard::Right);
	_in_j2.SetKeyPulo(sf::Keyboard::Up);
	_in_j2.SetKeyAtaque(sf::Keyboard::RShift);

	_jogador1.IniciarDoctor();
	_jogador2.IniciarRobo();

	_colisoes.Incluir(&_jogador1);
	_colisoes.Incluir(&_jogador2);
	_colisoes.SetListaInimigos(&_listaInimigos);
	_colisoes.SetListaPlataformas(&_listaPlataformas);
	_colisoes.SetListaProjAmigos(&_listaProjAmigos);
	_colisoes.SetListaProjInimigos(&_listaProjInimigos);

	_tex_fundo.loadFromFile("res/sprites/egypt_backg.png");
	_sp_fundo.setTexture(_tex_fundo);
	_sp_fundo.setScale(2, 2);

	_camera_x = 0;
}


Jogo::~Jogo () {
	delete _faseAtual;
	_faseAtual = NULL;
}

void Jogo::Executar () {
	if (_jogador1.GetMorreu() && (!_coop || _jogador2.GetMorreu())) {
		_acabou = true;
	}
	else if (_faseAtual->ChecarObjetivo()) {
		_acabou = true;
	}
	else {
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

	int desejado_camera_x = 0;

	if (!_jogador1.GetMorreu()) {
			desejado_camera_x += _jogador1.GetPosicao().x;
	}

	if (_coop && !_jogador2.GetMorreu()) {
		desejado_camera_x += _jogador2.GetPosicao().x;

		if (!_jogador1.GetMorreu()) {
			desejado_camera_x /= 2;
		}
	}

	// Interpolacao linear da camera
	_camera_x = _camera_x + (desejado_camera_x - _camera_x) * dt / 0.2;
	janela->SetCamera(_camera_x);

	_sp_fundo.setPosition(_camera_x - Janela::largura / 2, 0);
	janela->Desenhar(_sp_fundo);

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
	pFase->CarregaJogadores();
	pFase->CarregaPlataformas(&_listaPlataformas);
	pFase->CarregaInimigos(&_listaInimigos, &_listaProjInimigos);
}
