/*
	Classe Principal da aplicação

	Encapsula o projeto em um objeto, seguindo as boas praticas de POO

	Aplicacao eh o executavel como um todo
	Jogo eh apenas a cena onde os jogadores controlam personagens
*/

#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <SFML/Window.hpp>

#include "GerenciadorGrafico.h"
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
		EstadoApp _estado;
};

#endif // PRINCIPAL_H
