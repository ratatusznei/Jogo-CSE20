#include "Animador.h"

Animador::Animador (int n_animacoes) {
	_max_frames = new int[n_animacoes];
	_n_anims = n_animacoes;

	_anim_atual = 0;
	_quadro_atual = 0;

	_timer = 0;

	_terminou = false;
	_ehLoop = false;
}

Animador::~Animador () {
	delete[] _max_frames;
}

void Animador::Play (int indice) {
	if (indice != _anim_atual) {
		_anim_atual = indice;
		_quadro_atual = 0;
		_timer = 0;
		_terminou = false;

		_tex_rect->top = _anim_atual * _tamanho + _offSetY;
		_tex_rect->left = _quadro_atual * _tamanho;
		_sp->setTextureRect(*_tex_rect);
	}
}

void Animador::Executar (float dt) {
	_timer += dt;

	if (_timer > _periodo) {
		cout << _quadro_atual << endl;

		if (!_terminou) {
			_timer -= _periodo;

			_quadro_atual += 1;

			if (_quadro_atual >= _max_frames[_anim_atual]) {
				if (_ehLoop) {
					_quadro_atual = 0;
				}
				else {
					_quadro_atual = 0;
					_terminou = true;
				}
			}

			_tex_rect->top = _anim_atual * _tamanho + _offSetY;
			_tex_rect->left = _quadro_atual * _tamanho;
			_sp->setTextureRect(*_tex_rect);
		}
	}
}

void Animador::SetFrameCount (int indice, int count) {
	if (indice < _n_anims) {
		_max_frames[indice] = count;
	}
}

void Animador::SetTamanhoQuadro (int tamanho) {
	_tamanho = tamanho;

	_tex_rect->width = tamanho;
	_tex_rect->height = tamanho;
}

void Animador::SetOffSetY (int offset) {
	_offSetY = offset;
}

void Animador::SetPeriodo (float t) {
	_periodo = t;
}

void Animador::SetTextureBox (sf::IntRect* tex_rect) {
	_tex_rect = tex_rect;
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
