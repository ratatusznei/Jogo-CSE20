#include "Plataforma.h"

Plataforma::Plataforma (int x, int y, int w, int h):
Entidade(x, y, Resources::tex_plataforma),
_largura(w),
_altura(h),
_caixa_colisao(_sp.getGlobalBounds())
{
	// Pre calcula caixa de colisao
	_caixa_colisao.width *= _largura;
	_caixa_colisao.height *= _altura;
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

	_caixa_colisao.left = x;
	_caixa_colisao.top = y;
}

void Plataforma::SetTamanho (int w, int h) {
	_largura = w;
	_altura = h;

	sf::FloatRect temp = _sp.getGlobalBounds();

	_caixa_colisao.top = temp.top;
	_caixa_colisao.left = temp.left;
	_caixa_colisao.width = temp.width * _largura;
	_caixa_colisao.height = temp.height * _altura;
}

sf::IntRect Plataforma::GetCaixaDeColisao() {
	return _caixa_colisao;
}
