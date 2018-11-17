/*
	Personagem que se move pela fase, colidindo com plataformas
*/

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "../Animador.h"
#include "Entidade.h"
#include "Plataforma.h"
#include "Projetil.h"

class Personagem: public Entidade {
	public:
		Personagem (float x = 0, float y = 0, string tex_path = "", int n_animacoes = 1);
		~Personagem ();

		/*	IN: O dano causado
			OUT: Remove da vida o dano */
		void Machucar (int dano);

		void Atacar ();

		/*	IN: Delta tempo da ultima frame
			OUT: Calcula as novas propriedades do personagem */
		virtual void Executar (float dt) = 0;

		/*	IN: Nenhum
			OUT: Desenha o personagem na tela */
		void Desenhar ();

		/*	IN: Plataforma
			OUT: Retorna verdadeiro se o personagem esta colidindo com a plataforma: a baixo, em cima, a esquerda ou a direita, respectivamente */
		bool ChecarChao (Plataforma& plat);
		bool ChecarTeto (Plataforma& plat);
		bool ChecarEsquerda (Plataforma& plat);
		bool ChecarDireita (Plataforma& plat);

	protected:
		/*	IN: Delta tempo da ultima frame
			OUT: Atualiza as posicoes conforme velocidades e velocidades conforme aceleracoes */
		void AtualizarFisica (float dt);

		/*	IN: Delta tempo da ultima frame, magnetude da aceleracao
			OUT: Aplica uma aceleracao no sentido oposto ao movimento */
		void Desacelerar (float dt, float aceleracao);

		/*	IN: Delta tempo da ultima frame, magnetude da aceleracao
			OUT: Aplica uma aceleracao */
		void Acelerar (float dt, float aceleracao);

		Animador _animador;

		Projetil _projetil_protipo;
		int _offSetAtaqueX;
		int _offSetAtaqueY;
		int _vx_ataque;
		float _tempoPraMorrerAtaque;

		bool _podeAtacar;

		int _vida;

		sf::Vector2f _velocidade;
		sf::Vector2f _aceleracao;

		bool _esta_no_chao;
		bool _batendo_teto;
		bool _batendo_direta;
		bool _batendo_esquerda;

		float _max_vx;
		float _max_vy;

		float _aceleracao_caminhada;
		float _desaceleracao;

		float _velocidade_pulo;
};

#endif // PERSONAGEM_H
