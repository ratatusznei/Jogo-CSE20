/*
	Plataforma com a qual os personagens colidem
*/

#ifndef PLATAFORMA_H
#define PLATAFORMA_H

#include "../GerenciadorDeTexturas.h"
#include "Entidade.h"

class Plataforma: public Entidade {
	public:
		/*	IN: Posicao na janela e o tamanho da plataforma em blocos
			OUT: Cria a plataforma */
		Plataforma (int x = 0, int y = 0, int w = 0, int h = 0);
		~Plataforma ();

		void Desenhar ();
		void SetPosicao (int x, int y);
		void SetTamanho (int w, int h);

		sf::IntRect GetCaixaDeColisao();

	protected:
		int _largura;
		int _altura;

		sf::IntRect _caixa_colisao;
};

#endif // PLATAFORMA_H
