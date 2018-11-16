#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include "../common.h"
#include "Menu.h"

class MenuPrincipal: public Menu {
	public:
		MenuPrincipal ();
		~MenuPrincipal ();

	private:
		EstadoApp InterpretarEscolha (int botao_selecionado);
};

#endif // MENUPRINCIPAL_H
