#include "Inimigo.h"

Inimigo::Inimigo (float x, float y, string tex_path, int n_animacoes):
Personagem(x, y, tex_path, n_animacoes) {
	//ctor
}

Inimigo::~Inimigo () {
	//dtor
}

int Inimigo::QualTipo() {
	return _tipo;
}
