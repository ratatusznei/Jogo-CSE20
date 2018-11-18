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

void GerenciadorDeColisao::Incluir (Inimigo *pi) {
	_inimigos.colaNoFinal(pi);
}

void GerenciadorDeColisao::Incluir (Plataforma *pp) {
	_plataformas.colaNoFinal(pp);
}

void GerenciadorDeColisao::Calcular () {
	_jogadores.goToTop();

	do {
		if (!_inimigos.estaVazia()) {
			_inimigos.goToTop();
			do {
				if (_jogadores.getWhatIsHere()->GetCaixaDeColisao().intersects(_inimigos.getWhatIsHere()->GetCaixaDeColisao())) {
					/**** TEMPORARIO ****/
					_jogadores.getWhatIsHere()->Machucar(0);
				}
			} while(!(++_inimigos));
		}

		if (!_plataformas.estaVazia()) {
			_plataformas.goToTop();
			do {
				if(_jogadores.getWhatIsHere()->ChecarChao(*_plataformas.getWhatIsHere())){
					break;
				}
			} while(!(++_plataformas));


			_plataformas.goToTop();
			do {
				if(_jogadores.getWhatIsHere()->ChecarEsquerda(*_plataformas.getWhatIsHere())){
					break;
				}
			} while(!(++_plataformas));

			_plataformas.goToTop();
			do {
				if(_jogadores.getWhatIsHere()->ChecarDireita(*_plataformas.getWhatIsHere())){
					break;
				}
			} while(!(++_plataformas));

			_plataformas.goToTop();
			do {
				if(_jogadores.getWhatIsHere()->ChecarTeto(*_plataformas.getWhatIsHere())){
					break;
				}
			} while(!(++_plataformas));
		}
	}
	while(!(++_jogadores));

	if (!_inimigos.estaVazia() && !_plataformas.estaVazia()) {
		_inimigos.goToTop();
		do {
			_plataformas.goToTop();
			do {
				if(_inimigos.getWhatIsHere()->ChecarChao(*_plataformas.getWhatIsHere())){
					break;
				}
			} while(!(++_plataformas));

			_plataformas.goToTop();
			do {
				if(_inimigos.getWhatIsHere()->ChecarEsquerda(*_plataformas.getWhatIsHere())){
					break;
				}
			} while(!(++_plataformas));

			_plataformas.goToTop();
			do {
				if(_inimigos.getWhatIsHere()->ChecarDireita(*_plataformas.getWhatIsHere())){
					break;
				}
			} while(!(++_plataformas));

			_plataformas.goToTop();
			do {
				if(_inimigos.getWhatIsHere()->ChecarTeto(*_plataformas.getWhatIsHere())){
					break;
				}
			} while(!(++_plataformas));
		}
		while(!(++_inimigos));
	}
}
