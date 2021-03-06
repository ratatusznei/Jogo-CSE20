/*
	Entidade desenhavel na janela
*/

#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "../GerenciadorGrafico.h"
#include "../common.h"

class Entidade {
	public:
		Entidade (float x = 0, float y = 0);
		~Entidade ();

		/*	IN: Nenhum
			OUT: Desenha a entidade na janela */
		virtual void Desenhar ();

		/*	IN: Nenhum
			OUT: Retorna a caixa de colisao da entidade */
		virtual sf::IntRect GetCaixaDeColisao();

		/*	IN: Nenhum
			OUT: Posicao relativa ao TOPO-ESQUERDO da janela */
		const sf::Vector2f GetPosicao ();

		/*  IN: Posicao x, y
            OUT: Seta a posicao */
		void SetPosicao(int x, int y);

	protected:
		sf::IntRect _texRect;
		sf::Sprite _sp;

		sf::Vector2f _posicao;
		bool _viradoPraEsquerda;
};

#endif // ENTIDADE_H
