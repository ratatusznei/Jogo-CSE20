#include "TelaDeCreditos.h"

TelaDeCreditos::TelaDeCreditos () {
	SetFont(Resources::fonte_menu);
	SetFundo(Resources::fundo_tela_creditos);

	IncluirOpcao("Voltar", Janela::meia_largura, 360);
}

TelaDeCreditos::~TelaDeCreditos () {
	//dtor
}

EstadoApp TelaDeCreditos::InterpretarEscolha (int botao_selecionado) {
	if (botao_selecionado == 0) {
		return EstadoApp::Menu;
	}
}
