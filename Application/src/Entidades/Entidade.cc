#include "Entidade.h"

Entidade::Entidade (float x, float y, string tex_path):
_posicao(x, y),
_viradoPraEsquerda(true)
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
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();
	janela->Desenhar(_sp);
}

sf::IntRect Entidade::GetCaixaDeColisao () {
	// Caixa de colisao dinamica, nao eh pre calculada
	sf::FloatRect caixa_sp = _sp.getGlobalBounds();

	sf::IntRect caixa_col(caixa_sp);
	// Atualizando as coordenadas da caixa
	caixa_col.top = _posicao.y;
	caixa_col.left = _posicao.x;

	return caixa_col;
}

const sf::Vector2f Entidade::GetPosicao () {
	return _posicao;
}

void Entidade::SetPosicao(int x, int y) {
	_posicao.x = x;
	_posicao.y = y;
	_sp.setPosition(_posicao);
}
