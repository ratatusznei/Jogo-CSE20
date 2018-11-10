#ifndef JOGADOR_H
#define JOGADOR_H

#include "GerenciadorDeInput.h"
#include "../Personagem/Personagem.h"
#include "../common.h"

class Jogador: public Personagem {
	public:
		Jogador(GerenciadorDeInput *inputs = NULL);
		~Jogador();

		void Executar ();

	private:
		GerenciadorDeInput *_inputs;

		EstadoJogador _estado;
		unsigned _contador;
};

#endif // JOGADOR_H
