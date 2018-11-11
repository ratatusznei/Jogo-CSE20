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

void Personagem::AtualizarFisica (float dt) {
	_old_velocidade = _velocidade;
	_old_posicao = _posicao;

	_velocidade += _aceleracao * dt;
	_posicao += _velocidade * dt;

	if (_velocidade.x > _max_vx) {
		_velocidade.x = _max_vx;
	}
	else if (_velocidade.x < -_max_vx) {
		_velocidade.x = -_max_vx;
	}

	if (_velocidade.y > _max_vy) {
		_velocidade.y = _max_vy;
	}

	_aceleracao.x = 0;
	_aceleracao.y = 0;
	_sp.setPosition(_posicao);
}

void Personagem::Desacelerar (float dt, float aceleracao) {
	if (_velocidade.x > 0) {
		_aceleracao.x = -aceleracao;

		if (_velocidade.x < _aceleracao.x * dt) {
			_velocidade.x = 0;
			_aceleracao.x = 0;
		}
	}
	else if (_velocidade.x < 0) {
		_aceleracao.x = aceleracao;

		if (_velocidade.x > -_aceleracao.x * dt) {
			_velocidade.x = 0;
			_aceleracao.x = 0;
		}
	}
}

void Personagem::Acelerar(float dt, float aceleracao) {
	// Acelera. Se estiver mudando a direcao
	//  zera a velocidade para nao ter que desacelerar antes

	_aceleracao.x = aceleracao;

	bool sinais_opostos = (_velocidade.x < 0 && aceleracao > 0) || (_velocidade.x > 0 && aceleracao < 0);

	if (sinais_opostos) {
		_velocidade.x = 0;
	}
}
