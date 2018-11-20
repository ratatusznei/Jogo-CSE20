/*
	Inimigo: Mumia

	Segue os jogadores que chegam perto
	Fica patrulhando (perdida) se nao tem jogador perto
*/

#ifndef MUMIA_H
#define MUMIA_H

#include "../GerenciadorDeTexturas.h"
#include "../GerenciadorGrafico.h"
#include "../Inimigos/Inimigo.h"
#include "../Jogador/Jogador.h"
#include "../common.h"

class Mumia: public Inimigo {
	enum class EstadoMumia {
		SeguindoJ1,
		SeguindoJ2,
		Perdida,
		Atacando,
		PulandoParaJ1,
		PulandoParaJ2,
		Pulando,
	};

	public:
		Mumia(Jogador *j1 = NULL, Jogador *j2 = NULL, Lista<Projetil*>* projeteis = NULL, int x = 0, int y = 0);
		~Mumia();

		void Executar (float dt);

	private:
		EstadoMumia _estado;

};

#endif // MUMIA_H
