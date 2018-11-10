#include "Personagem.h"

Personagem::Personagem (float x, float y, string tex_path):
Entidade(x, y, tex_path)
{
	//ctor
}

Personagem::~Personagem () {
	//dtor
}

void Personagem::Machucar (int dano) {
	_vida -= dano;
}

void Personagem::Mover () {
	float dt = GerenciadorGrafico::GetInstance()->GetDeltaTime();

	_old_posicao = _posicao;
	_old_velocidade = _velocidade;

	_posicao += _velocidade * dt;
	_velocidade += _aceleracao * dt;

	_sp.setPosition(_posicao);
}

void Personagem::Desenhar () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();

	if (_velocidade.x > 0) {
		_sp.setScale(Resources::pixel_scale, Resources::pixel_scale);
		_sp.setOrigin(0, 0);
	}
	else if (_velocidade.x < 0) {
		_sp.setOrigin(_sp.getLocalBounds().width, 0);
		_sp.setScale(-Resources::pixel_scale, Resources::pixel_scale);
	}

	janela->Desenhar(_sp);
}
