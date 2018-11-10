#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal (EnumEstado& estado):
Menu(estado)
{
	SetFont(Resources::fonte_menu);
        SetFundo(Resources::fundo_menu_principal);

	IncluiOpcao("Jogar solo", Janela::meia_largura, 200);
	IncluiOpcao("Jogar co-op", Janela::meia_largura, 250);
	IncluiOpcao("Carregar jogo", Janela::meia_largura, 300);
	IncluiOpcao("Creditos", Janela::meia_largura, 350);
	IncluiOpcao("Sair", Janela::meia_largura, 430);
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
