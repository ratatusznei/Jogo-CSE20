#ifndef ANIMADOR_H
#define ANIMADOR_H

#include <SFML/Graphics.hpp>
#include "common.h"

class Animador {
	public:
		Animador(int n_animacoes);
		~Animador();

		void Executar (float dt);
		void Play (int indice);
		void Restart ();

		void SetFrameCount (int indice, int count);
		void SetTamanhoQuadro (int tamanho);
		void SetOffSetY (int offset);
		void SetPeriodo (float t);

		void SetTextureBox (sf::IntRect* tex_rect);
		void SetSprite (sf::Sprite* sprite);
		void SetLoop (bool do_loop);

		bool GetTerminou ();

	private:
		// Ponteiro de vetor
		int *_max_frames;
		int _n_anims;

		int _anim_atual;
		int _quadro_atual;

		int _tamanho;
		int _offSetY;

		bool _ehLoop;
		bool _terminou;

		float _periodo;
		float _timer;

		sf::IntRect* _tex_rect;
		sf::Sprite* _sp;
};

#endif // ANIMADOR_H
