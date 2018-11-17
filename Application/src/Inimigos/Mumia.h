/*
	Inimigo: Mumia

	Segue os jogadores que chegam perto
	Fica patrulhando se nao tem jogador perto
*/

#ifndef MUMIA_H
#define MUMIA_H

#include "../GerenciadorGrafico.h"
#include "../Inimigos/Inimigo.h"
#include "../Jogador/Jogador.h"
#include "../common.h"

class Mumia: public Inimigo {
	enum class EstadoMumia {
		SeguindoJ1,
		SeguindoJ2,
		Perdida,
	};

	public:
		Mumia(Jogador *j1 = NULL, Jogador *j2 = NULL, int x = 0, int y = 0);
		~Mumia();

		void Executar (float dt);

	private:
		Jogador *_j1;
		Jogador *_j2;

		int _x0;
		float _range;

		EstadoMumia _estado;

};

#endif // MUMIA_H
