#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal (EnumEstado& estado):
Menu(estado)
{
	SetFont("data/fonts/BLKCHCRY.TTF");
	IncluiOpcao("Jogar solo", WINDOW_LENGTH / 2, 200);
	IncluiOpcao("Jogar co-op", WINDOW_LENGTH / 2, 250);
	IncluiOpcao("Carregar jogo", WINDOW_LENGTH / 2, 300);
	IncluiOpcao("Creditos", WINDOW_LENGTH / 2, 350);
	IncluiOpcao("Sair", WINDOW_LENGTH / 2, 430);
}

MenuPrincipal::~MenuPrincipal () {
	//dtor
}

void MenuPrincipal::InterpretaClick (int indice) {
	switch (indice) {
	case 0:
		//solo
		break;

	case 1:
		//coop
		break;

	case 2:
		//carregar
		break;

	case 3:
		_estado = EnumEstado::Tela_de_creditos;
		break;

	case 4:
		_estado = EnumEstado::Sair;
		break;

	default:
		break;
	}
}
