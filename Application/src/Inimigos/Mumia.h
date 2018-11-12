#ifndef MUMIA_H
#define MUMIA_H

#include "../GerenciadorGrafico.h"
#include "../Entidades/Personagem.h"
#include "../Jogador/Jogador.h"
#include "../common.h"

const int distancia_deteccao = 150;
const int aceleracao_mumia = 300;
const int desaceleracao_mumia = 500;

const int max_vx_mumia = 40;
const int max_vy_mumia = Fisica::velocidade_terminal;

class Mumia: public Personagem {
	enum class EstadoMumia {
		SeguindoJ1,
		SeguindoJ2,
		Perdida,
	};

	public:
		Mumia(Jogador *j1 = NULL, Jogador *j2 = NULL);
		~Mumia();

		void Executar (float dt);

	private:
		Jogador *_j1;
		Jogador *_j2;

		EstadoMumia _estado;

};

#endif // MUMIA_H
