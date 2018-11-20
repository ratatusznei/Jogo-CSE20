/*
	Inimigo: Bad Robot

	Segue os jogadores que chegam perto
	Fica patrulhando se nao tem jogador perto
*/

#ifndef BADROBOT_H
#define BADROBOT_H

#include "../GerenciadorDeTexturas.h"
#include "../GerenciadorGrafico.h"
#include "../Inimigos/Inimigo.h"
#include "../Jogador/Jogador.h"
#include "../common.h"

class BadRobot: public Inimigo {
	enum class EstadoBRobot {
		SeguindoJ1,
		SeguindoJ2,
		Perdido,
		Atacando,
		PulandoParaJ1,
		PulandoParaJ2,
		Pulando,
	};

	public:
		BadRobot(Jogador *j1 = NULL, Jogador *j2 = NULL, Lista<Projetil*>* projeteis = NULL, int x = 0, int y = 0);
		~BadRobot();

		void Executar (float dt);

	private:
		EstadoBRobot _estado;

};

#endif // BADROBOT_H

