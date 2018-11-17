/*
	Menu principal da aplicacao

	Possui botoes para entrar no jogo, sair da aplicacao, ver tela de creditos
*/

#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include "Menu.h"
#include "../common.h"

class MenuPrincipal: public Menu {
	public:
		MenuPrincipal ();
		~MenuPrincipal ();

	private:
		EstadoApp InterpretarEscolha (int botao_selecionado);
};

#endif // MENUPRINCIPAL_H
