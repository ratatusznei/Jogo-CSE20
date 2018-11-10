#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

namespace Janela {
	const int largura = 960;
	const int altura = 540;

	const int meia_largura = largura / 2;
	const int meia_altura = altura / 2;

	const string titulo = "Time Travel";
}

namespace Resources {
	const string fonte_menu = "res/fonts/BLKCHCRY.TTF";
	const string fundo_menu_principal = "res/backgrounds/menu_principal.png";
	const string fundo_tela_creditos = "res/backgrounds/tela_creditos.png";

	const string tex_jogador = "res/jogador.png";
}

namespace Propriedades {
	const float G = 16;
	const float velocidade_terminal = 500;

	const float atrito_ar = 0.6;
	const float atrito_chao = 0.2;

	const float aceleracao_jogador = 200;
	const float velocidade_max_jogador = 500;
	const float velocidade_pulo_jogador = 500;
}

enum class EstadoApp {
	Nenhum = 0,
	Menu,
	Jogo,
	Tela_de_creditos,
	Sair,
};

enum class EstadoJogador {
	Parado = 0,
	Andando,
	Pulando,
	Atacando,
	Machucado,
};

enum class Direcao {
	Esquerda = -1,
	Direita = 1,
};

#endif // COMMON_H_INCLUDED
