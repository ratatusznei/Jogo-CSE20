#include "GerenciadorDeColisao.h"

GerenciadorDeColisao::GerenciadorDeColisao () {
	//ctor
}

GerenciadorDeColisao::~GerenciadorDeColisao () {
	//dtor
}

void GerenciadorDeColisao::Incluir (Jogador *pj) {
	_jogadores.colaNoFinal(pj);
}

void GerenciadorDeColisao::SetListaInimigos (Lista<Inimigo*>* pLista) {
	_inimigos = pLista;
}
void GerenciadorDeColisao::SetListaPlataformas (Lista<Plataforma*>* pLista) {
	_plataformas = pLista;
}

void GerenciadorDeColisao::SetListaProjInimigos (Lista<Projetil*>* pLista) {
	_projInimigos = pLista;
}

void GerenciadorDeColisao::SetListaProjAmigos (Lista<Projetil*>* pLista) {
	_projAmigos = pLista;
}

void GerenciadorDeColisao::Calcular () {
	_jogadores.goToTop();

	// Colisoes com jogadores
	if (!_jogadores.estaVazia()) {
		do {
			Jogador* pj = _jogadores.getWhatIsHere();

			if (!_inimigos->estaVazia()) {
				_inimigos->goToTop();
				do {
					Inimigo* ii = _inimigos->getWhatIsHere();

					if (pj->GetCaixaDeColisao().intersects(ii->GetCaixaDeColisao())) {
						pj->Machucar(1);
					}
				} while(!(++(*_inimigos)));
			}

			if (!_projInimigos->estaVazia()) {
				_projInimigos->goToTop();
				do {
					Projetil* pp = _projInimigos->getWhatIsHere();

					if (pj->GetCaixaDeColisao().intersects(pp->GetCaixaDeColisao())) {
						pj->Machucar(pp->GetDano());

						_projInimigos->removeWhatIsHere();
						--(*_projInimigos);
					}
				} while(!(++(*_projInimigos)));
			}

			if (!_plataformas->estaVazia()) {
				_plataformas->goToTop();
				do {
					if(pj->ChecarChao(_plataformas->getWhatIsHere())){
						break;
					}
				} while(!(++(*_plataformas)));


				_plataformas->goToTop();
				do {
					if(pj->ChecarEsquerda(_plataformas->getWhatIsHere())){
						break;
					}
				} while(!(++(*_plataformas)));

				_plataformas->goToTop();
				do {
					if(pj->ChecarDireita(_plataformas->getWhatIsHere())){
						break;
					}
				} while(!(++(*_plataformas)));

				_plataformas->goToTop();
				do {
					if(pj->ChecarTeto(_plataformas->getWhatIsHere())){
						break;
					}
				} while(!(++(*_plataformas)));
			}
		}
		while(!(++_jogadores));
	}

	// Colisoes com inimigos
	if (!_inimigos->estaVazia() && !_plataformas->estaVazia()) {
		_inimigos->goToTop();
		do {
			Inimigo* ii = _inimigos->getWhatIsHere();

			if (!_projAmigos->estaVazia()) {
				_projAmigos->goToTop();
				do {
					Projetil* pp = _projAmigos->getWhatIsHere();

					if (ii->GetCaixaDeColisao().intersects(pp->GetCaixaDeColisao())) {
						ii->Machucar(pp->GetDano());

						_projAmigos->removeWhatIsHere();
						--(*_projAmigos);
					}
				} while(!(++(*_projAmigos)));
			}

			_plataformas->goToTop();
			do {
				if(ii->ChecarChao(_plataformas->getWhatIsHere())){
					break;
				}
			} while(!(++(*_plataformas)));

			_plataformas->goToTop();
			do {
				if(ii->ChecarEsquerda(_plataformas->getWhatIsHere())){
					break;
				}
			} while(!(++(*_plataformas)));

			_plataformas->goToTop();
			do {
				if(ii->ChecarDireita(_plataformas->getWhatIsHere())){
					break;
				}
			} while(!(++(*_plataformas)));

			_plataformas->goToTop();
			do {
				if(ii->ChecarTeto(_plataformas->getWhatIsHere())){
					break;
				}
			} while(!(++(*_plataformas)));
		}
		while(!(++(*_inimigos)));
	}
}
