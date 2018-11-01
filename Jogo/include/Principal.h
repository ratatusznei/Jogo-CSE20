#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <SFML/Window.hpp>

#include "GerenciadorGrafico.h"
#include "Menu.h"
#include "Jogo.h"
#include "TelaDeCreditos.h"

class Principal
{
	public:
		Principal ();
		~Principal ();

		void Executar ();

	private:
		GerenciadorGrafico _janela;
		Menu _menu;
		Jogo _jogo;
		TelaDeCreditos _creditos;
		EnumEstado _estado;
};

#endif // PRINCIPAL_H
