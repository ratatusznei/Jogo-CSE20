#include "Jogo.h"
#include<time.h>

Jogo::Jogo ():
_jogador1(&_in_j1, 20, 50),
_jogador2(&_in_j2, 680, 0)
{
	srand(clock());

	_fase1 = new FaseEgito(&_jogador1, &_jogador2);

	CarregarFase(_fase1);

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

	if (!_listaPlataformas.estaVazia()) {
		_listaPlataformas.goToTop();
		do {
			_colisoes.Incluir(_listaPlataformas.getWhatIsHere());
		} while(!(++_listaPlataformas));
	}

	if (!_listaInimigos.estaVazia()) {
		_listaInimigos.goToTop();
		do {
			_colisoes.Incluir(_listaInimigos.getWhatIsHere());
		} while(!(++_listaInimigos));
	}


	_tex_fundo.loadFromFile("res/sprites/egypt_backg.png");
	_sp_fundo.setTexture(_tex_fundo);
	_sp_fundo.setScale(2, 2);
}


Jogo::~Jogo () {
	//dtor
}

void Jogo::Executar () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();
	float dt = janela->GetDeltaTime();
	int camera_x;


	if (_coop) {
		camera_x = (_jogador1.GetPosicao().x + _jogador2.GetPosicao().x) / 2;
	}
	else {
		camera_x = _jogador1.GetPosicao().x;
	}

	janela->SetCamera(camera_x);

	_sp_fundo.setPosition(camera_x - Janela::largura / 2, 0);
	janela->Desenhar(_sp_fundo);

	_jogador1.Executar(dt);
	_jogador1.Desenhar();

	if (_coop) {
		_jogador2.Executar(dt);
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

			pi->Executar(dt);
			pi->Desenhar();
		} while(!(++_listaInimigos));
	}

	Projetil::ExecutarTodos(dt);
	Projetil::DesenharTodos();

	_colisoes.Calcular();
}

void Jogo::Desenhar () {

}

void Jogo::Iniciar(bool ehCoop) {
	_coop = ehCoop;
}

void Jogo::CarregarFase (Fase *pFase) {
	pFase->CarregaPlataformas(&_listaPlataformas);
	pFase->CarregaInimigos(&_listaInimigos);
}
