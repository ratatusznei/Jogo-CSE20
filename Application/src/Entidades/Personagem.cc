#include "Personagem.h"

Personagem::Personagem (float x, float y, string tex_path, int n_animacoes):
Entidade(x, y, tex_path),
_animador(n_animacoes),
_projetil_protipo(tex_path),
_esta_no_chao(false),
_batendo_teto(false),
_batendo_direta(false),
_batendo_esquerda(false)
{
	_tex_rect.top = 0;
	_tex_rect.left = 0;
	_tex_rect.width = Resources::block_size;
	_tex_rect.height = Resources::block_size;
	_sp.setTextureRect(_tex_rect);

	_offSetAtaqueX = 0;
	_offSetAtaqueY = 0;
	_vx_ataque = 100;
	_tempoPraMorrerAtaque = 1;
}

Personagem::~Personagem () {
	//dtor
}

void Personagem::Machucar (int dano) {
	_vida -= dano;
	/**** TEMPORARIO ****/
	_posicao.y -= 100;
}

void Personagem::Atacar () {
	Projetil* pp = new Projetil(_projetil_protipo);

	pp->SetPosicao(_posicao.x + _offSetAtaqueX, _posicao.y + _offSetAtaqueY);

	if (_viradoPraEsquerda) {
		pp->SetVelocidade(_vx_ataque);
	}
	else {
		pp->SetVelocidade(-_vx_ataque);
	}

	Projetil::Incluir(pp);
}

void Personagem::Desenhar () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();

	if (_viradoPraEsquerda) {
		_sp.setScale(Resources::pixel_scale, Resources::pixel_scale);
		_sp.setOrigin(0, 0);
	}
	else {
		_sp.setOrigin(_sp.getLocalBounds().width, 0);
		_sp.setScale(-Resources::pixel_scale, Resources::pixel_scale);
	}

	janela->Desenhar(_sp);
}

void Personagem::AtualizarFisica (float dt) {
	_velocidade += _aceleracao * dt;
	_posicao += _velocidade * dt;

	if (_velocidade.x > 0.1) {
		_viradoPraEsquerda = true;
	}
	else if (_velocidade.x < -0.1) {
		_viradoPraEsquerda = false;
	}

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

		if (_velocidade.x < aceleracao * dt) {
			_velocidade.x = 0;
			_aceleracao.x = 0;
		}
	}
	else if (_velocidade.x < 0) {
		_aceleracao.x = aceleracao;

		if (_velocidade.x > -aceleracao * dt) {
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
	int xf = pers_rect.left + pers_rect.width - 2;

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
	int xf = pers_rect.left + pers_rect.width - 2;

	// Colisao da linha com plataforma
	if (	(xf < plat_rect.left) ||
		(x0 > plat_rect.left + plat_rect.width) ||
		(y < plat_rect.top) ||
		(y > plat_rect.top + plat_rect.height)) {

		_batendo_teto = false;
		return false;
	}
	else {
		if (_velocidade.y < 0.01) {
			_posicao.y = plat_rect.top + plat_rect.height;
			_velocidade.y = 0;
			_batendo_teto = true;
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

		_batendo_esquerda = false;
		return false;
	}
	else {
		if (_velocidade.x < 0.01) {
			_posicao.x = plat_rect.left + plat_rect.width;
			_velocidade.x = 0;
			_batendo_esquerda = true;
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

		_batendo_direta = false;
		return false;
	}
	else {
		if (_velocidade.x > -0.01) {
			_posicao.x = plat_rect.left - pers_rect.width;
			_velocidade.x = 0;
			_batendo_direta = true;
		}

		return true;
	}
}
