#include "Inimigo.h"

Inimigo::Inimigo (float x, float y, Lista<Projetil*>* projeteis, int n_animacoes):
Personagem(x, y, projeteis, n_animacoes) {
	//ctor
}

Inimigo::~Inimigo () {
	//dtor
}

int Inimigo::QualTipo() {
	return _tipo;
}
