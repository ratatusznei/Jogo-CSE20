#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include "../common.h"
#include "Menu.h"

class MenuPrincipal: public Menu {
	public:
		MenuPrincipal(EstadoApp& estado);
		~MenuPrincipal();

	private:
		void InterpretarClick (int indice);
};

#endif // MENUPRINCIPAL_H
