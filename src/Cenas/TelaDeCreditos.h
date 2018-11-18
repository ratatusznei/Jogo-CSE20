/*
	Tela de creditos

	Tem um botao para voltar ao menu iniciar
	E o fundo possui os creditos
*/

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
