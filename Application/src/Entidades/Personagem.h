#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "Entidade.h"
#include "Plataforma.h"

class Personagem: public Entidade {
	public:
		Personagem (float x = 0, float y = 0, string tex_path = "");
		~Personagem ();

		void Machucar (int dano);

		virtual void Executar (float dt) = 0;
		void Desenhar ();

		// y do chao eh saida
		bool ChecarChao (Plataforma& plat);
		bool ChecarTeto (Plataforma& plat);
		bool ChecarEsquerda (Plataforma& plat);
		bool ChecarDireita (Plataforma& plat);

	protected:
		void AtualizarFisica (float dt);
		void Desacelerar (float dt, float aceleracao);
		void Acelerar (float dt, float aceleracao);

		int _vida;

		sf::Vector2f _velocidade;
		sf::Vector2f _aceleracao;

		bool _esta_no_chao;
		bool _batendo_teto;
		bool _batendo_direta;
		bool _batendo_esquerda;

		float _max_vx;
		float _max_vy;
};

#endif // PERSONAGEM_H
