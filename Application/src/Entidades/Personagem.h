#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Entidade.h"

class Personagem: public Entidade {
	public:
		Personagem (float x = 0, float y = 0, string tex_path = "");
		~Personagem ();

		void Machucar (int dano);

		void Mover ();

		virtual void Executar () = 0;
		void Desenhar ();

	protected:
		int _vida;

		sf::Vector2f _old_posicao;

		sf::Vector2f _velocidade;
		sf::Vector2f _old_velocidade;

		sf::Vector2f _aceleracao;

		bool _esta_no_chao;
};

#endif // PERSONAGEM_H
