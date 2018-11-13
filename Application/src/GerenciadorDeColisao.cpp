#include "GerenciadorDeColisao.h"

GerenciadorDeColisao::GerenciadorDeColisao () {
	//ctor
}

GerenciadorDeColisao::~GerenciadorDeColisao () {
	//dtor
}

void GerenciadorDeColisao::Incluir (Jogador *pj) {
	_jogadores.push_back(pj);
}

void GerenciadorDeColisao::Incluir (Inimigo *pi) {
	_inimigos.push_back(pi);
}

void GerenciadorDeColisao::Incluir (Plataforma *pp) {
	_plataformas.push_back(pp);
}

void GerenciadorDeColisao::Calcular () {
	list<Jogador*>::iterator ji;
	list<Inimigo*>::iterator ii;
	list<Plataforma*>::iterator pi;

	for (ji = _jogadores.begin(); ji != _jogadores.end(); ji++) {
		for (ii = _inimigos.begin(); ii != _inimigos.end(); ii++) {
			if ((*ji)->GetCaixaDeColisao().intersects((*ii)->GetCaixaDeColisao())) {
				/**** TEMPORARIO ****/
				(*ji)->Machucar(0);
			}
		}

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
