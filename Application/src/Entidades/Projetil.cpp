#include "Projetil.h"

Lista<Projetil*> Projetil::projeteis;

void Projetil::Incluir(Projetil* pp) {
	projeteis.colaNoFinal(pp);
}

void Projetil::ExecutarTodos(float dt) {
	if (!projeteis.estaVazia()) {
		projeteis.goToTop();

		do {
			Projetil* pp = projeteis.getWhatIsHere();

			pp->Executar(dt);

			if(pp->GetMorreu()) {
				projeteis.removeWhatIsHere();
				delete pp;
				--projeteis;
			}
		} while (!(++projeteis));
	}
}

void Projetil::DesenharTodos () {
	if (!projeteis.estaVazia()) {
		projeteis.goToTop();

		do {
			projeteis.getWhatIsHere()->Desenhar();
		} while (!(++projeteis));
	}
}

Projetil::Projetil ():
Entidade(0, 0),
_velocidade(0, 0),
_tempoPraMorrer(0)
{
	_tex_rect.top = 0;
	_tex_rect.left = 0;
	_tex_rect.width = Resources::block_size;
	_tex_rect.height = Resources::block_size;
	_sp.setTextureRect(_tex_rect);
}

Projetil::Projetil(Projetil& prototipo, int x, int y, int vx, int vy):
Entidade(x, y),
_velocidade(vx, vy),
_tempoPraMorrer(prototipo.GetTempoPraMorrer())
{
	_texture = prototipo.GetTexture();
	_sp.setTexture(*_texture);

	_tex_rect.top = 0;
	_tex_rect.left = 0;
	_tex_rect.width = Resources::block_size;
	_tex_rect.height = Resources::block_size;
	_sp.setTextureRect(_tex_rect);
}

Projetil::~Projetil () {
}

sf::Texture* Projetil::GetTexture () {
	return _texture;
}

void Projetil::SetTexture (sf::Texture *tex) {
	_texture = tex;
	_sp.setTexture(*_texture);
}

void Projetil::SetVelocidade(int vx) {
	_velocidade.x = vx;
}

void Projetil::SetTempoPraMorrer (float t) {
	_tempoPraMorrer = t;
}

float Projetil::GetTempoPraMorrer () {
	return _tempoPraMorrer;
}

bool Projetil::GetMorreu () {
	return _tempoPraMorrer < 0;
}

void Projetil::Desenhar () {
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

void Projetil::Executar (float dt) {
	_posicao.x += _velocidade.x * dt;
	_posicao.y += _velocidade.y * dt;

	if (_velocidade.x > 0.1) {
		_viradoPraEsquerda = true;
	}
	else if (_velocidade.x < -0.1) {
		_viradoPraEsquerda = false;
	}

	_tempoPraMorrer -= dt;
	_sp.setPosition(_posicao);
}