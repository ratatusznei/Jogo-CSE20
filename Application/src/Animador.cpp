#include "Animador.h"

Animador::Animador (int n_animacoes) {
	_maxFrames = new int[n_animacoes];
	_nAnims = n_animacoes;

	_animAtual = 0;
	_quadroAtual = 0;

	_timer = 0;

	_terminou = false;
	_ehLoop = false;
}

Animador::~Animador () {
	delete[] _maxFrames;
}

void Animador::Play (int indice) {
	if (indice != _animAtual) {
		_animAtual = indice;
		_quadroAtual = 0;
		_timer = 0;
		_terminou = false;

		_texRect->top = _animAtual * _tamanho + _offSetY;
		_texRect->left = _quadroAtual * _tamanho;
		_sp->setTextureRect(*_texRect);
	}
}

void Animador::Restart () {
	_quadroAtual = 0;
	_timer = 0;
	_terminou = false;

	_texRect->top = _animAtual * _tamanho + _offSetY;
	_texRect->left = _quadroAtual * _tamanho;
	_sp->setTextureRect(*_texRect);
}

void Animador::Executar (float dt) {
	_timer += dt;

	if (_timer > _periodo) {
		if (!_terminou) {
			_timer -= _periodo;

			_quadroAtual += 1;

			if (_quadroAtual >= _maxFrames[_animAtual]) {
				if (_ehLoop) {
					_quadroAtual = 0;
				}
				else {
					_quadroAtual = 0;
					_terminou = true;
				}
			}

			_texRect->top = _animAtual * _tamanho + _offSetY;
			_texRect->left = _quadroAtual * _tamanho;
			_sp->setTextureRect(*_texRect);
		}
	}
}

void Animador::SetFrameCount (int indice, int count) {
	if (indice < _nAnims) {
		_maxFrames[indice] = count;
	}
}

void Animador::SetTamanhoQuadro (int tamanho) {
	_tamanho = tamanho;

	_texRect->width = tamanho;
	_texRect->height = tamanho;
}

void Animador::SetOffSetY (int offset) {
	_offSetY = offset;
}

void Animador::SetPeriodo (float t) {
	_periodo = t;
}

void Animador::SetTextureBox (sf::IntRect* tex_rect) {
	_texRect = tex_rect;
}

void Animador::SetSprite (sf::Sprite* sprite) {
	_sp = sprite;
}

void Animador::SetLoop (bool do_loop) {
	_ehLoop = do_loop;
}

bool Animador::GetTerminou () {
	return _terminou;
}
