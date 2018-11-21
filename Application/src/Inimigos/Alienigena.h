/*
	Inimigo: Alienigena

	Atira nos jogadores que chegam perto
	Fica patrulhando se nao tem jogador perto
*/

#ifndef ALIENIGENA_H
#define ALIENIGENA_H

#include "../GerenciadorDeTexturas.h"
#include "../GerenciadorGrafico.h"
#include "../Inimigos/Inimigo.h"
#include "../Jogador/Jogador.h"
#include "../common.h"

class Alienigena: public Inimigo {
	enum class EstadoAlien {
		SeguindoJ1,
		SeguindoJ2,
		Perdido,
		Atacando,
		PulandoParaJ1,
		PulandoParaJ2,
		Pulando,
	};

	public:
		Alienigena(Jogador *j1 = NULL, Jogador *j2 = NULL, Lista<Projetil*>* projeteis = NULL, int x = 0, int y = 0);
		~Alienigena();

		void Executar (float dt);

	private:
		float _timerDescanso;

		EstadoAlien _estado;

};

#endif // ALIENIGENA_H

