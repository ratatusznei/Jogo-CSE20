#ifndef TELADECREDITOS_H
#define TELADECREDITOS_H

#include <string>
#include "../common.h"
#include "Menu.h"

using namespace std;

class TelaDeCreditos: public Menu {
	public:
		TelaDeCreditos ();
		~TelaDeCreditos ();

	private:
		EstadoApp InterpretarEscolha (int botao_selecionado);
};

#endif // TELADECREDITOS_H
