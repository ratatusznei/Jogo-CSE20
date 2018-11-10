#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include "../common.h"
#include "Menu.h"

class MenuPrincipal: public Menu {
	public:
		MenuPrincipal(EnumEstado& estado);
		~MenuPrincipal();

	private:
		void InterpretaClick (int indice);
};

#endif // MENUPRINCIPAL_H
