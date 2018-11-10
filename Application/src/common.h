#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

namespace Janela {
	const int largura = 960;
	const int altura = 540;

	const int meia_largura = largura / 2;
	const int meia_altura = altura / 2;

	const char titulo[] = "Jogo";
}

enum class EnumEstado {
	Nenhum = 0,
	Menu,
	Jogo,
	Tela_de_creditos,
	Sair,
};

#endif // COMMON_H_INCLUDED
