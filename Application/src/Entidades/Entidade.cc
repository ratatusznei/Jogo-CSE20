#include "Entidade.h"

Entidade::Entidade (float x, float y, string tex_path):
_posicao(x, y)
{
	_tex.loadFromFile(tex_path);

	_sp.setTexture(_tex);
	_sp.setScale(Resources::pixel_scale, Resources::pixel_scale);
	_sp.setPosition(_posicao);
}

Entidade::~Entidade () {
	//dtor
}

void Entidade::Desenhar () {
}
