#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <string>

using namespace std;

namespace Janela {
	const int largura = 960;
	const int altura = 540;

	const int meia_largura = largura / 2;
	const int meia_altura = altura / 2;

	const string titulo = "Jogo";
}

namespace Resources {
	const string fonte_menu = "res/fonts/BLKCHCRY.TTF";
	const string fundo_menu_principal = "res/backgrounds/menu_principal.png";
	const string fundo_tela_creditos = "res/backgrounds/tela_creditos.png";
}

enum class EnumEstado {
	Nenhum = 0,
	Menu,
	Jogo,
	Tela_de_creditos,
	Sair,
};

#endif // COMMON_H_INCLUDED
