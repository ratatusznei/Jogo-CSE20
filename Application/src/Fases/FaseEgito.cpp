#include "FaseEgito.h"

FaseEgito::FaseEgito (Jogador *j1, Jogador* j2):
Fase(j1, j2)
{
	IncluiPlataforma(0, Janela::altura - Resources::block_size, 1, 50);

	IncluiSpawnMumia(300, 0);
	IncluiSpawnMumia(350, 0);
	IncluiSpawnMumia(400, 0);
	IncluiSpawnMumia(450, 0);
	IncluiSpawnMumia(500, 0);
	IncluiSpawnMumia(550, 0);
	IncluiSpawnMumia(600, 0);
	IncluiSpawnMumia(650, 0);
	IncluiSpawnMumia(700, 0);
	IncluiSpawnMumia(750, 0);

	chefe = NULL;
}

FaseEgito::~FaseEgito () {
	//dtor
}

bool FaseEgito::ChecarObjetivo () {
	return chefe->GetMorreu();
}

void FaseEgito::CarregaJogadores () {
	_j1->SetPosicao(20, 20);
	_j2->SetPosicao(50, 20);
}

void FaseEgito::CarregaInimigos (Lista<Inimigo*>* _pLista, Lista<Projetil*>* projeteis) {
	int n_mumias = rand() % 5 + 5;

	while (n_mumias > 0 && !_listaSpawnMumia.estaVazia()) {
		_listaSpawnMumia.goToTop();

		sf::Vector2i* pos = _listaSpawnMumia.getWhatIsHere();
		_listaSpawnMumia.removeWhatIsHere();

		Inimigo* pi = (Inimigo*) new Mumia(_j1, _j2, projeteis, pos->x, pos->y);
		_pLista->colaNoFinal(pi);

		n_mumias--;
	}

	chefe = new Mumia(_j1, _j2, projeteis, 1000, 0);
	_pLista->colaNoFinal(chefe);
}

void FaseEgito::CarregaPlataformas (Lista<Plataforma*>* _pLista) {
	if (!_listaPlataformas.estaVazia()) {
		_listaPlataformas.goToTop();

		do {
			_pLista->colaNoFinal(_listaPlataformas.getWhatIsHere());
		} while (!(++_listaPlataformas));
	}
}

void FaseEgito::IncluiSpawnMumia (int x, int y) {
	_listaSpawnMumia.colaNoFinal(new sf::Vector2i(x, y));
}

void FaseEgito::IncluiSpawnCobra (int x, int y) {
	_listaSpawnCobra.colaNoFinal(new sf::Vector2i(x, y));
}

void FaseEgito::IncluiPlataforma (int x, int y, int h, int w) {
	Plataforma* pp = new Plataforma(x, y, w, h);
	_listaPlataformas.colaNoFinal(pp);
}
