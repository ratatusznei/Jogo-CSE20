#include "Inimigo.h"

Inimigo::Inimigo (float x, float y, string tex_path):
Personagem(x, y, tex_path) {
	//ctor
}

Inimigo::~Inimigo () {
	//dtor
}

int Inimigo::QualTipo() {
	return _tipo;
}
