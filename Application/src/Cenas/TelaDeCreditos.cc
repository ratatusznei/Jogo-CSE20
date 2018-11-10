#include "TelaDeCreditos.h"

TelaDeCreditos::TelaDeCreditos (EnumEstado& estado):
Menu(estado)
{
	SetFont(Resources::fonte_menu);
	SetFundo(Resources::fundo_tela_creditos);

	IncluiOpcao("Voltar", Janela::meia_largura, 360);
}

TelaDeCreditos::~TelaDeCreditos () {
	//dtor
}

void TelaDeCreditos::InterpretaClick (int indice) {
	if (indice == 0) {
		_estado = EnumEstado::Menu;
	}
}
