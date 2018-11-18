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
			if (!_inimigos->estaVazia()) {
				_inimigos->goToTop();
				do {
					if (_jogadores.getWhatIsHere()->GetCaixaDeColisao().intersects(_inimigos->getWhatIsHere()->GetCaixaDeColisao())) {
						/**** TEMPORARIO ****/
						_jogadores.getWhatIsHere()->Machucar(1);
					}
				} while(!(++(*_inimigos)));
			}

			if (!_projInimigos->estaVazia()) {
				_projInimigos->goToTop();
				do {
					if (_jogadores.getWhatIsHere()->GetCaixaDeColisao().intersects(_projInimigos->getWhatIsHere()->GetCaixaDeColisao())) {
						/**** TEMPORARIO ****/
						_jogadores.getWhatIsHere()->Machucar(1);
					}
				} while(!(++(*_projInimigos)));
			}

			if (!_plataformas->estaVazia()) {
				_plataformas->goToTop();
				do {
					if(_jogadores.getWhatIsHere()->ChecarChao(_plataformas->getWhatIsHere())){
						break;
					}
				} while(!(++(*_plataformas)));


				_plataformas->goToTop();
				do {
					if(_jogadores.getWhatIsHere()->ChecarEsquerda(_plataformas->getWhatIsHere())){
						break;
					}
				} while(!(++(*_plataformas)));

				_plataformas->goToTop();
				do {
					if(_jogadores.getWhatIsHere()->ChecarDireita(_plataformas->getWhatIsHere())){
						break;
					}
				} while(!(++(*_plataformas)));

				_plataformas->goToTop();
				do {
					if(_jogadores.getWhatIsHere()->ChecarTeto(_plataformas->getWhatIsHere())){
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
			if (!_projAmigos->estaVazia()) {
				_projAmigos->goToTop();
				do {
					if (_inimigos->getWhatIsHere()->GetCaixaDeColisao().intersects(_projAmigos->getWhatIsHere()->GetCaixaDeColisao())) {
						/**** TEMPORARIO ****/
						_inimigos->getWhatIsHere()->Machucar(1);
					}
				} while(!(++(*_projAmigos)));
			}

			_plataformas->goToTop();
			do {
				if(_inimigos->getWhatIsHere()->ChecarChao(_plataformas->getWhatIsHere())){
					break;
				}
			} while(!(++(*_plataformas)));

			_plataformas->goToTop();
			do {
				if(_inimigos->getWhatIsHere()->ChecarEsquerda(_plataformas->getWhatIsHere())){
					break;
				}
			} while(!(++(*_plataformas)));

			_plataformas->goToTop();
			do {
				if(_inimigos->getWhatIsHere()->ChecarDireita(_plataformas->getWhatIsHere())){
					break;
				}
			} while(!(++(*_plataformas)));

			_plataformas->goToTop();
			do {
				if(_inimigos->getWhatIsHere()->ChecarTeto(_plataformas->getWhatIsHere())){
					break;
				}
			} while(!(++(*_plataformas)));
		}
		while(!(++(*_inimigos)));
	}
}
