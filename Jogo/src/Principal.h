#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <SFML/Window.hpp>

#include "Cenas/GerenciadorGrafico.h"
#include "Cenas/MenuPrincipal.h"
#include "Cenas/Jogo.h"
#include "Cenas/TelaDeCreditos.h"

class Principal {
	public:
		Principal ();
		~Principal ();

		void Executar ();

	private:
		MenuPrincipal _main;
		Jogo _jogo;
		TelaDeCreditos _creditos;
		EnumEstado _estado;
};

#endif // PRINCIPAL_H
