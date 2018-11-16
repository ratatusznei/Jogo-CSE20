#include "MenuPrincipal.h"

MenuPrincipal::MenuPrincipal () {
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

EstadoApp MenuPrincipal::InterpretarEscolha (int botao_selecionado) {
	switch (botao_selecionado) {
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
		return EstadoApp::Tela_de_creditos;
		break;

	case 4:
		return EstadoApp::Sair;
		break;

	default:
		break;
	}

	return EstadoApp::Nenhum;
}
