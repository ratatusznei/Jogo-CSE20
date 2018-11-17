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

		void IniciarRobo ();
		void IniciarDoctor ();

		/*	IN: O delta tempo da ultima frame
			OUT: Calcula novas propriedades do jogador conforme entradas */
		void Executar (float dt);

	private:
		GerenciadorDeInput *_inputs;

		EstadoJogador _estado;

		float _vmin_pulo;
};

#endif // JOGADOR_H
