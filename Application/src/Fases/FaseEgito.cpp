#include "FaseEgito.h"

FaseEgito::FaseEgito (Jogador *j1, Jogador* j2):
Fase(j1, j2)
{
	const int bs = Resources::block_size * Resources::pixel_scale;
	const int altitude0 = Janela::altura - bs;

	IncluiPlataforma(0, altitude0, 69, 2);
	IncluiPlataforma(71 * bs, altitude0, 15, 2);
	IncluiPlataforma(89 * bs, altitude0, 64, 2);
	IncluiPlataforma(155 * bs, altitude0, 30, 2);
	IncluiPlataforma(185 * bs, altitude0 - 9 * bs, 1, 10);

	IncluiPlataforma(15 * bs, altitude0 - 5 * bs, 1, 1);
	IncluiPlataforma(20 * bs, altitude0 - 5 * bs, 5, 1);
	IncluiPlataforma(22 * bs, altitude0 - 9 * bs, 1, 1);
	IncluiPlataforma(77 * bs, altitude0 - 5 * bs, 3, 1);
	IncluiPlataforma(80 * bs, altitude0 - 9 * bs, 8, 1);
	IncluiPlataforma(91 * bs, altitude0 - 9 * bs, 4, 1);
	IncluiPlataforma(94 * bs, altitude0 - 5 * bs, 1, 1);
	IncluiPlataforma(100 * bs, altitude0 - 5 * bs, 2, 1);
	IncluiPlataforma(106 * bs, altitude0 - 5 * bs, 1, 1);
	IncluiPlataforma(109 * bs, altitude0 - 5 * bs, 1, 1);
	IncluiPlataforma(109 * bs, altitude0 - 9 * bs, 1, 1);
	IncluiPlataforma(112 * bs, altitude0 - 5 * bs, 1, 1);
	IncluiPlataforma(118 * bs, altitude0 - 5 * bs, 1, 1);
	IncluiPlataforma(121 * bs, altitude0 - 9 * bs, 3, 1);
	IncluiPlataforma(128 * bs, altitude0 - 9 * bs, 4, 1);
	IncluiPlataforma(129 * bs, altitude0 - 5 * bs, 2, 1);

	IncluiPlataforma(134 * bs, altitude0 - 1 * bs, 4, 1);
	IncluiPlataforma(135 * bs, altitude0 - 2 * bs, 3, 1);
	IncluiPlataforma(136 * bs, altitude0 - 3 * bs, 2, 1);
	IncluiPlataforma(137 * bs, altitude0 - 4 * bs, 1, 1);
	IncluiPlataforma(140 * bs, altitude0 - 1 * bs, 4, 1);
	IncluiPlataforma(140 * bs, altitude0 - 2 * bs, 3, 1);
	IncluiPlataforma(140 * bs, altitude0 - 3 * bs, 2, 1);
	IncluiPlataforma(140 * bs, altitude0 - 4 * bs, 1, 1);

	IncluiPlataforma(148 * bs, altitude0 - 1 * bs, 5, 1);
	IncluiPlataforma(149 * bs, altitude0 - 2 * bs, 4, 1);
	IncluiPlataforma(150 * bs, altitude0 - 3 * bs, 3, 1);
	IncluiPlataforma(151 * bs, altitude0 - 4 * bs, 2, 1);

	IncluiSpawnCobra(22 * bs, altitude0 - 1 * bs);
	IncluiSpawnMumia(40 * bs, altitude0 - 1 * bs);
	IncluiSpawnCobra(51 * bs, altitude0 - 1 * bs);
	IncluiSpawnCobra(52 * bs, altitude0 - 1 * bs);
	IncluiSpawnMumia(80 * bs, altitude0 - 10 * bs);
	IncluiSpawnCobra(82 * bs, altitude0 - 10 * bs);
	IncluiSpawnMumia(97 * bs, altitude0 - 1 * bs);
	IncluiSpawnMumia(98 * bs, altitude0 - 1 * bs);
	IncluiSpawnMumia(107 * bs, altitude0 - 1 * bs);
	IncluiSpawnCobra(114 * bs, altitude0 - 1 * bs);
	IncluiSpawnMumia(115 * bs, altitude0 - 1 * bs);
	IncluiSpawnCobra(124 * bs, altitude0 - 1 * bs);
	IncluiSpawnMumia(125 * bs, altitude0 - 1 * bs);
	IncluiSpawnMumia(127 * bs, altitude0 - 1 * bs);
	IncluiSpawnCobra(128 * bs, altitude0 - 1 * bs);

	_chefeX = 174 * bs;
	_chefeY = altitude0 - 1 * bs;
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
	int n_cobras = rand() % 5 + 5;

	while (n_mumias > 0 && !_listaSpawnMumia.estaVazia()) {
		_listaSpawnMumia.goToTop();

		sf::Vector2i* pos = _listaSpawnMumia.getWhatIsHere();
		_listaSpawnMumia.removeWhatIsHere();

		Inimigo* pi = (Inimigo*) new Mumia(_j1, _j2, projeteis, pos->x, pos->y);
		_pLista->colaNoFinal(pi);

		n_mumias--;
	}
	while (n_cobras > 0 && !_listaSpawnCobra.estaVazia()) {
		_listaSpawnCobra.goToTop();

		sf::Vector2i* pos = _listaSpawnCobra.getWhatIsHere();
		_listaSpawnCobra.removeWhatIsHere();

		Inimigo* pi = (Inimigo*) new Cobra(_j1, _j2, projeteis, pos->x, pos->y);
		_pLista->colaNoFinal(pi);

		n_mumias--;
	}

	chefe = new Mumia(_j1, _j2, projeteis, _chefeX, _chefeY);
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

void FaseEgito::IncluiPlataforma (int x, int y, int w, int h) {
	Plataforma* pp = new Plataforma(x, y, w, h, GerenciadorDeTexturas::GetInstance()->GetPlataformaEgito());
	_listaPlataformas.colaNoFinal(pp);
}
