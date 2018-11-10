#ifndef TELADECREDITOS_H
#define TELADECREDITOS_H

#include <string>
#include "../common.h"
#include "Menu.h"

using namespace std;

class TelaDeCreditos: public Menu {
	public:
		TelaDeCreditos (EnumEstado& estado);
		~TelaDeCreditos ();

	private:
		void InterpretaClick (int indice);
};

#endif // TELADECREDITOS_H
