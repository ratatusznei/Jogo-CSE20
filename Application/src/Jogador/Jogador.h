#ifndef JOGADOR_H
#define JOGADOR_H

#include "GerenciadorDeInput.h"
#include "../Entidades/Personagem.h"
#include "../common.h"

class Jogador: public Personagem {
	public:
		Jogador(GerenciadorDeInput *inputs = NULL);
		~Jogador();

		void Executar (float dt);
		const sf::Vector2f GetPosicao ();

	private:
		GerenciadorDeInput *_inputs;

		EstadoJogador _estado;
};

#endif // JOGADOR_H
