#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Entidade.h"

class Personagem: public Entidade {
	public:
		Personagem (float x = 0, float y = 0, string tex_path = "");
		~Personagem ();

		void Machucar (int dano);

		virtual void Executar () = 0;
		void Desenhar ();

	protected:
		void AtualizarFisica (float dt);
		void Desacelerar (float dt, float aceleracao);
		void Acelerar (float dt, float aceleracao);

		int _vida;

		sf::Vector2f _old_posicao;

		sf::Vector2f _velocidade;
		sf::Vector2f _old_velocidade;

		sf::Vector2f _aceleracao;

		bool _esta_no_chao;
		float _max_vx;
		float _max_vy;
};

#endif // PERSONAGEM_H
