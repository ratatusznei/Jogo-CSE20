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
		EnumEstado _estado;
		GerenciadorGrafico _janela;
		TelaDeCreditos _creditos;
		Menu _menu;
		Jogo _jogo;
};

#endif // PRINCIPAL_H
