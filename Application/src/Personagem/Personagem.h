#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "../GerenciadorGrafico.h"
#include "../common.h"

class Personagem {
	public:
		Personagem ();
		~Personagem ();

		void Machucar (int dano);

		void Mover ();

		virtual void Executar () = 0;
		void Desenhar ();

	protected:
		sf::Texture _tex;
		sf::IntRect _tex_rect;
		sf::Sprite _sp;

		int _vida;

		sf::Vector2f _posicao;
		sf::Vector2f _old_posicao;

		sf::Vector2f _velocidade;
		sf::Vector2f _old_velocidade;

		sf::Vector2f _aceleracao;

		bool _esta_no_chao;
};

#endif // PERSONAGEM_H
