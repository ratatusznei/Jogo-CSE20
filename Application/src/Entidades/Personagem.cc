#include "Personagem.h"

Personagem::Personagem (float x, float y, Lista<Projetil*>* projeteis, int n_animacoes):
Entidade(x, y),
_animador(n_animacoes),
_projetilProtipo(),
_listaProjeteis(projeteis),
_estaNoChao(false),
_batendoTeto(false),
_batendoDireta(false),
_batendoEsquerda(false)
{
	_vida = 1;

	_texRect.top = 0;
	_texRect.left = 0;
	_texRect.width = Resources::block_size;
	_texRect.height = Resources::block_size;
	_sp.setTextureRect(_texRect);

	_offSetAtaqueX = Resources::block_size / 2;
	_offSetAtaqueY = 0;
	_vXAtaque = 100;
	_tempoPraMorrerAtaque = 1;
}

Personagem::~Personagem () {
	//dtor
}

void Personagem::Machucar (int dano) {
	if(PodeMachucar()){
		_vida -= dano;
	}
}

bool Personagem::GetMorreu () {
	return _vida <= 0;
}

void Personagem::Atacar () {
	Projetil* pp = new Projetil(_projetilProtipo);

	if (_viradoPraEsquerda) {
		pp->SetPosicao(_posicao.x + _offSetAtaqueX, _posicao.y + _offSetAtaqueY);
		pp->SetVelocidade(_vXAtaque);
	}
	else {
		pp->SetPosicao(_posicao.x - _offSetAtaqueX, _posicao.y + _offSetAtaqueY);
		pp->SetVelocidade(-_vXAtaque);
	}

	_listaProjeteis->colaNoFinal(pp);
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

	if (_velocidade.x > _maxVx) {
		_velocidade.x = _maxVx;
	}
	else if (_velocidade.x < -_maxVx) {
		_velocidade.x = -_maxVx;
	}

	if (_velocidade.y > _maxVy) {
		_velocidade.y = _maxVy;
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

bool Personagem::ChecarChao (Plataforma* plat) {
	sf::IntRect plat_rect = plat->GetCaixaDeColisao();
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

		_estaNoChao = false;
		return false;
	}
	else {
		if (_velocidade.y > -0.01) {
			_posicao.y = plat_rect.top - pers_rect.height;
			_velocidade.y = 0;
			_estaNoChao = true;
		}
		return true;
	}
}

bool Personagem::ChecarTeto (Plataforma* plat) {
	sf::IntRect plat_rect = plat->GetCaixaDeColisao();
	sf::IntRect pers_rect = GetCaixaDeColisao();

	// Linha em cima do personagem
	int y = pers_rect.top - 10;
	int x0 = pers_rect.left + 1;
	int xf = pers_rect.left + pers_rect.width - 1;

	// Colisao da linha com plataforma
	if ((xf < plat_rect.left) ||
		(x0 > plat_rect.left + plat_rect.width) ||
		(y < plat_rect.top) ||
		(y > plat_rect.top + plat_rect.height)) {

		_batendoTeto = false;
		return false;
	}
	else {
		if (_velocidade.y < 0.01) {
			_posicao.y = plat_rect.top + plat_rect.height;
			_velocidade.y = 0;
			_batendoTeto = true;
		}

		return true;
	}
}

bool Personagem::ChecarEsquerda (Plataforma* plat) {
	sf::IntRect plat_rect = plat->GetCaixaDeColisao();
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

		_batendoEsquerda = false;
		return false;
	}
	else {
		if (_velocidade.x < 0.01) {
			_posicao.x = plat_rect.left + plat_rect.width;
			_velocidade.x = 0;
			_batendoEsquerda = true;
		}

		return true;
	}
}

bool Personagem::ChecarDireita (Plataforma* plat) {
	sf::IntRect plat_rect = plat->GetCaixaDeColisao();
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

		_batendoDireta = false;
		return false;
	}
	else {
		if (_velocidade.x > -0.01) {
			_posicao.x = plat_rect.left - pers_rect.width;
			_velocidade.x = 0;
			_batendoDireta = true;
		}

		return true;
	}
}

bool Personagem::PodeMachucar(){
	return true;
}
