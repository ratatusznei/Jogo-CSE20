#include "Plataforma.h"

Plataforma::Plataforma (int x, int y, int w, int h):
Entidade(x, y, Resources::tex_plataforma),
largura(w),
altura(h),
_caixa_colisao(_sp.getGlobalBounds())
{
	// Pre calcula caixa de colisao
	_caixa_colisao.width *= largura;
	_caixa_colisao.height *= altura;
}

Plataforma::~Plataforma () {
	//dtor
}

void Plataforma::Desenhar () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();

	for (int y = 0; y < altura; y++) {
		for (int x = 0; x < largura; x++) {
			_sp.setPosition(
				_posicao.x + x * Resources::pixel_scale * _sp.getLocalBounds().width,
				_posicao.y + y * Resources::pixel_scale * _sp.getLocalBounds().height
			);

			janela->Desenhar(_sp);
		}
	}

	_sp.setPosition(_posicao);
}

sf::IntRect Plataforma::GetCaixaDeColisao() {
	return _caixa_colisao;
}
