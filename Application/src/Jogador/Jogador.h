/*
	Jogador

	Responsavel por ler entradas, executar e atualizar o personagem
*/

#ifndef JOGADOR_H
#define JOGADOR_H

#include "../GerenciadorDeTexturas.h"
#include "GerenciadorDeInput.h"
#include "../Entidades/Personagem.h"
#include "../common.h"

enum class EstadoJogador {
	Parado = 0,
	Andando,
	Pulando,
	Atacando,
};

class Jogador: public Personagem {
	public:
		Jogador(GerenciadorDeInput *inputs = NULL, Lista<Projetil*>* projeteis = NULL, int x = 0, int y = 0);
		~Jogador();

		/*  IN: Nenhum
            OUT: Inicializa a instancia como um dos personagens jogaveis */
		void IniciarRobo ();
		void IniciarDoctor ();

		/*  IN: O dano causado
            OUT: Reduz o dano da vida */
		void Machucar (int dano);

		/*	IN: O tempo da ultima frame
			OUT: Calcula novas propriedades do jogador conforme entradas */
		void Executar (float dt);

	private:
		GerenciadorDeInput *_inputs;

		EstadoJogador _estado;

		float _vMinPulo;

		float _timerMachucado;
		float _piscadorMachucado;
};

#endif // JOGADOR_H
