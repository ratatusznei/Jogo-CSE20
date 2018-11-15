#ifndef JOGO_H
#define JOGO_H

#include"../GerenciadorGrafico.h"
#include"fase.h"
#include"MenuPrincipal.h"

class Jogo {
	public:
		Jogo ();
		~Jogo ();

		void Executar ();
		void Desenhar ();

	private:

	    MenuPrincipal m;
	    Fase f;

};

#endif // JOGO_H
