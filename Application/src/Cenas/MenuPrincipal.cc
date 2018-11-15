#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal (EstadoApp& estado):
Menu(estado)
{
	SetFont(Resources::fonte_menu);
        SetFundo(Resources::fundo_menu_principal);

	IncluirOpcao("Jogar solo", Janela::meia_largura, 200);
	IncluirOpcao("Jogar co-op", Janela::meia_largura, 250);
	IncluirOpcao("Carregar jogo", Janela::meia_largura, 300);
	IncluirOpcao("Creditos", Janela::meia_largura, 350);
	IncluirOpcao("Sair", Janela::meia_largura, 430);
}

MenuPrincipal::MenuPrincipal():
Menu(EstadoApp::Menu){

    SetFont(Resources::fonte_menu);
        SetFundo(Resources::fundo_menu_principal);

	IncluirOpcao("Jogar solo", Janela::meia_largura, 200);
	IncluirOpcao("Jogar co-op", Janela::meia_largura, 250);
	IncluirOpcao("Carregar jogo", Janela::meia_largura, 300);
	IncluirOpcao("Creditos", Janela::meia_largura, 350);
	IncluirOpcao("Sair", Janela::meia_largura, 430);

}

MenuPrincipal::~MenuPrincipal () {
	//dtor
}

void MenuPrincipal::InterpretarClick (int indice) {
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
		_estado = EstadoApp::Tela_de_creditos;
		break;

	case 4:
		_estado = EstadoApp::Sair;
		break;

	default:
		break;
	}
}
