#include "Plataforma.h"

Plataforma::Plataforma (int x, int y, int w, int h, sf::Texture* tex):
Entidade(x, y),
_largura(w),
_altura(h),
_caixaDeColisao(x, y, 0, 0)
{
	_sp.setTexture(*tex);

	// Pre calcular caixa de colisao
	_caixaDeColisao.width = _largura * _sp.getGlobalBounds().width;
	_caixaDeColisao.height = _altura * _sp.getGlobalBounds().height;
}

Plataforma::~Plataforma () {
	//dtor
}

void Plataforma::Desenhar () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();

	for (int y = 0; y < _altura; y++) {
		for (int x = 0; x < _largura; x++) {
			_sp.setPosition(
				_posicao.x + x * Resources::pixel_scale * _sp.getLocalBounds().width,
				_posicao.y + y * Resources::pixel_scale * _sp.getLocalBounds().height
			);

			janela->Desenhar(_sp);
		}
	}

	_sp.setPosition(_posicao);
}

void Plataforma::SetPosicao (int x, int y) {
	_posicao.x = x;
	_posicao.y = y;

	_caixaDeColisao.left = x;
	_caixaDeColisao.top = y;
}

void Plataforma::SetTamanho (int w, int h) {
	_largura = w;
	_altura = h;

	sf::FloatRect temp = _sp.getGlobalBounds();

	_caixaDeColisao.top = temp.top;
	_caixaDeColisao.left = temp.left;
	_caixaDeColisao.width = temp.width * _largura;
	_caixaDeColisao.height = temp.height * _altura;
}

sf::IntRect Plataforma::GetCaixaDeColisao() {
	return _caixaDeColisao;
}
