#include "TelaDeCreditos.h"

TelaDeCreditos::TelaDeCreditos (EnumEstado& estado):
Menu(estado)
{
	IncluiOpcao("Voltar", Janela::meia_largura, 360);
	IncluiOpcao("Creditos", Janela::meia_largura, 100);
}

TelaDeCreditos::~TelaDeCreditos () {
	//dtor
}

void TelaDeCreditos::InterpretaClick (int indice) {
	if (indice == 0) {
		_estado = EnumEstado::Menu;
	}
}
