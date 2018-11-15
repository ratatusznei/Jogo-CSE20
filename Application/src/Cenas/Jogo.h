#ifndef JOGO_H
#define JOGO_H

#include "../GerenciadorGrafico.h"
#include "../Fases/Fase.h"

class Jogo {
	public:
		Jogo ();
		~Jogo ();

		void Executar ();
		void Desenhar ();

	private:
		Fase _fase;

};

#endif // JOGO_H
