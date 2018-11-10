#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "../GerenciadorGrafico.h"
#include "../common.h"

class Entidade {
	public:
		Entidade (float x = 0, float y = 0, string tex_path = "");
		~Entidade ();

		virtual void Desenhar ();

	protected:
		sf::Texture _tex;
		sf::IntRect _tex_rect;
		sf::Sprite _sp;

		sf::Vector2f _posicao;
};

#endif // ENTIDADE_H
