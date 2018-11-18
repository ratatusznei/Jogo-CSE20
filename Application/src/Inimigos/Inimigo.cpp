#include "Inimigo.h"

Inimigo::Inimigo (float x, float y, int n_animacoes):
Personagem(x, y, n_animacoes) {
	//ctor
}

Inimigo::~Inimigo () {
	//dtor
}

int Inimigo::QualTipo() {
	return _tipo;
}
