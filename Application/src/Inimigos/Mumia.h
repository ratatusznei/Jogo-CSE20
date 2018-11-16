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

const int distancia_deteccao = 120;
const int aceleracao_mumia = 300;
const int desaceleracao_mumia = 500;

const int v_pulo_mumia = Fisica::v0_pulo_jogador;

const int max_vx_mumia = 40;
const int max_vy_mumia = Fisica::velocidade_terminal;

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

		EstadoMumia _estado;

};

#endif // MUMIA_H
