#include "DiretorDeColisao.h"

DiretorDeColisao::DiretorDeColisao () {
	//ctor
}

DiretorDeColisao::~DiretorDeColisao () {
	//dtor
}

void DiretorDeColisao::Incluir (Jogador *pj) {
	_jogadores.push_back(pj);
}

void DiretorDeColisao::Incluir (Mumia *pi) {
	_inimigos.push_back(pi);
}

void DiretorDeColisao::Incluir (Plataforma *pp) {
	_plataformas.push_back(pp);
}

void DiretorDeColisao::Calcular () {
	list<Jogador*>::iterator ji;
	list<Mumia*>::iterator ii;
	list<Plataforma*>::iterator pi;

	for (ji = _jogadores.begin(); ji != _jogadores.end(); ji++) {
		for (pi = _plataformas.begin(); pi != _plataformas.end(); pi++) {
			if ((*ji)->ChecarChao(**pi)) {
				break;
			}
		}

		for (pi = _plataformas.begin(); pi != _plataformas.end(); pi++) {
			if ((*ji)->ChecarTeto(**pi)) {
				break;
			}
		}

		for (pi = _plataformas.begin(); pi != _plataformas.end(); pi++) {
			if ((*ji)->ChecarEsquerda(**pi)) {
				break;
			}
		}

		for (pi = _plataformas.begin(); pi != _plataformas.end(); pi++) {
			if ((*ji)->ChecarDireita(**pi)) {
				break;
			}
		}
 	}

	for (ii = _inimigos.begin(); ii != _inimigos.end(); ii++) {
		for (pi = _plataformas.begin(); pi != _plataformas.end(); pi++) {
			if ((*ii)->ChecarChao(**pi)) {
				break;
			}
		}

		for (pi = _plataformas.begin(); pi != _plataformas.end(); pi++) {
			if ((*ii)->ChecarTeto(**pi)) {
				break;
			}
		}

		for (pi = _plataformas.begin(); pi != _plataformas.end(); pi++) {
			if ((*ii)->ChecarEsquerda(**pi)) {
				break;
			}
		}

		for (pi = _plataformas.begin(); pi != _plataformas.end(); pi++) {
			if ((*ii)->ChecarDireita(**pi)) {
				break;
			}
		}
 	}
}
