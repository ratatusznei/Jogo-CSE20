/*
	Jogador

	Responsavel por ler entradas, executar e atualizar o personagem
*/

#ifndef JOGADOR_H
#define JOGADOR_H

#include "GerenciadorDeInput.h"
#include "../Entidades/Personagem.h"
#include "../common.h"

class Jogador: public Personagem {
	public:
		Jogador(GerenciadorDeInput *inputs = NULL, int x = 0, int y = 0);
		~Jogador();

		/*	IN: O delta tempo da ultima frame
			OUT: Calcula novas propriedades do jogador conforme entradas */
		void Executar (float dt);

		/*	IN: Nenhum
			OUT: Posicao relativa ao TOPO-ESQUERDO da janela */
		const sf::Vector2f GetPosicao ();

	private:
		GerenciadorDeInput *_inputs;

		EstadoJogador _estado;
};

#endif // JOGADOR_H
