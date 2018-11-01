#include "TelaDeCreditos.h"

TelaDeCreditos::TelaDeCreditos (EnumEstado& estado):
Menu(estado)
{
	IncluiOpcao("Voltar", WINDOW_LENGTH / 2, 360);

	IncluiOpcao("Creditos", WINDOW_LENGTH / 2, 100);
}

TelaDeCreditos::~TelaDeCreditos () {
	//dtor
}

void TelaDeCreditos::InterpretaClick (int indice) {
	if (indice == 0) {
		_estado = EnumEstado::Menu;
	}
}
