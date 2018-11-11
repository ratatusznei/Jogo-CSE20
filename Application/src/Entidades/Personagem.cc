#include "Personagem.h"

Personagem::Personagem (float x, float y, string tex_path):
Entidade(x, y, tex_path)
{
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

bool Personagem::ChecarChao (Plataforma& plat) {
	sf::IntRect plat_rect = plat.GetCaixaDeColisao();
	sf::IntRect pers_rect = GetCaixaDeColisao();

	// Linha 1px embaixo do personagem
	int y = pers_rect.top + pers_rect.height + 1;
	int x0 = pers_rect.left + 2;
	int xf = pers_rect.left + pers_rect.width - 1;

	// Colisao da linha com plataforma
	if (	(xf < plat_rect.left) ||
		(x0 > plat_rect.left + plat_rect.width) ||
		(y < plat_rect.top) ||
		(y > plat_rect.top + plat_rect.height)) {

		_esta_no_chao = false;
		return false;
	}
	else {
		if (_velocidade.y > -0.01) {
			_posicao.y = plat_rect.top - pers_rect.height;
			_velocidade.y = 0;
			_esta_no_chao = true;
		}
		return true;
	}
}

bool Personagem::ChecarTeto (Plataforma& plat) {
	sf::IntRect plat_rect = plat.GetCaixaDeColisao();
	sf::IntRect pers_rect = GetCaixaDeColisao();

	// Linha 1px em cima do personagem
	int y = pers_rect.top - 1;
	int x0 = pers_rect.left + 2;
	int xf = pers_rect.left + pers_rect.width - 1;

	// Colisao da linha com plataforma
	if (	(xf < plat_rect.left) ||
		(x0 > plat_rect.left + plat_rect.width) ||
		(y < plat_rect.top) ||
		(y > plat_rect.top + plat_rect.height)) {

		return false;
	}
	else {
		if (_velocidade.y < 0.01) {
			_posicao.y = plat_rect.top + plat_rect.height;
			_velocidade.y = 0;
		}

		return true;
	}
}

bool Personagem::ChecarEsquerda (Plataforma& plat) {
	sf::IntRect plat_rect = plat.GetCaixaDeColisao();
	sf::IntRect pers_rect = GetCaixaDeColisao();

	// Linha 1px a esquerda do personagem
	int x = pers_rect.left - 1;
	int y0 = pers_rect.top + 1;
	int yf = pers_rect.top + pers_rect.height - 1;

	// Colisao da linha com plataforma
	if (	(yf < plat_rect.top) ||
		(y0 > plat_rect.top + plat_rect.height) ||
		(x < plat_rect.left) ||
		(x > plat_rect.left + plat_rect.width)) {

		return false;
	}
	else {
		if (_velocidade.x < 0.01) {
			_posicao.x = plat_rect.left + plat_rect.width;
			_velocidade.x = 0;
		}

		return true;
	}
}

bool Personagem::ChecarDireita (Plataforma& plat) {
	sf::IntRect plat_rect = plat.GetCaixaDeColisao();
	sf::IntRect pers_rect = GetCaixaDeColisao();

	// Linha 1px a direita do personagem
	int x = pers_rect.left + pers_rect.width + 1;
	int y0 = pers_rect.top + 1;
	int yf = pers_rect.top + pers_rect.height - 1;

	// Colisao da linha com plataforma
	if (	(yf < plat_rect.top) ||
		(y0 > plat_rect.top + plat_rect.height) ||
		(x < plat_rect.left) ||
		(x > plat_rect.left + plat_rect.width)) {

		return false;
	}
	else {
		if (_velocidade.x > -0.01) {
			_posicao.x = plat_rect.left - pers_rect.width;
			_velocidade.x = 0;
		}

		return true;
	}
}
