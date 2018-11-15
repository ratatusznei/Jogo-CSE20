#include "DiretorDeColisao.h"

DiretorDeColisao::DiretorDeColisao () {
	//ctor
}

DiretorDeColisao::~DiretorDeColisao () {
	//dtor
}

void DiretorDeColisao::Incluir (Jogador *pj) {
	_jogadores.colaNoFinal(pj);
}

void DiretorDeColisao::Incluir (Plataforma *pp) {
	_plataformas.colaNoFinal(pp);
}

void DiretorDeColisao::Calcular () {

	_jogadores.goToTop();
	_plataformas.goToTop();
	do{
		do{
			if(_jogadores.getWhatIsHere()->ChecarChao(_plataformas.getWhatIsHere())){
				break;
			}
			if(_jogadores.getWhatIsHere()->ChecarEsquerda(_plataformas.getWhatIsHere())){
			   	break;
			}
			if(_jogadores.getWhatIsHere()->ChecarDireita(_plataformas.getWhatIsHere())){
			   	break;
			}
			if(_jogadores.getWhatIsHere()->ChecarTeto(_plataformas.getWhatIsHere())){
			  	break;
			}
		}
		while(!(++_plataformas));
	}
	while(!(++_jogadores));
}
