/*
	Inimigo: Cobra

	Atira nos jogadores que estao por perto
	Fica patrulhando se nao tem jogador perto
*/

#ifndef COBRA_H
#define COBRA_H

#include "../GerenciadorDeTexturas.h"
#include "../GerenciadorGrafico.h"
#include "../Inimigos/Inimigo.h"
#include "../Jogador/Jogador.h"
#include "../common.h"

class Cobra: public Inimigo {
	enum class EstadoCobra {
		SeguindoJ1,
		SeguindoJ2,
		Perdida,
		Atacando,
	};

	public:
		Cobra(Jogador *j1 = NULL, Jogador *j2 = NULL, Lista<Projetil*>* projeteis = NULL, int x = 0, int y = 0);
		~Cobra();

		void Executar (float dt);

	private:
		Jogador *_j1;
		Jogador *_j2;

		int _x0;
		float _timerDescanso;
		float _range;
		float _range_ataque;

		EstadoCobra _estado;

};

#endif // COBRA_H

