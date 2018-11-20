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
		Plataforma (int x = 0, int y = 0, int w = 0, int h = 0, sf::Texture* tex = GerenciadorDeTexturas::GetInstance()->GetPlataforma());
		~Plataforma ();

		void Desenhar ();

		/*  IN: Posicao x, y da plataforma
            OUT: Seta a posicao */
		void SetPosicao (int x, int y);

		/*  IN: Tamanho da plataforma em blocos
            OUT: Seta o tamanho */
		void SetTamanho (int w, int h);

		/*  IN: Nenhum
            OUT: A caixa de colisao relativa ao top esquerdo da janela */
		sf::IntRect GetCaixaDeColisao();

	protected:
		int _largura;
		int _altura;

		sf::IntRect _caixaDeColisao;
};

#endif // PLATAFORMA_H
