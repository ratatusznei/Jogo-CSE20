/*
	Entidade desenhavel na janela
*/

#ifndef ENTIDADE_H
#define ENTIDADE_H

#include "../GerenciadorGrafico.h"
#include "../common.h"

class Entidade {
	public:
		Entidade (float x = 0, float y = 0, string tex_path = "");
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

	protected:
		sf::Texture _tex;
		sf::IntRect _tex_rect;
		sf::Sprite _sp;

		sf::Vector2f _posicao;
};

#endif // ENTIDADE_H
