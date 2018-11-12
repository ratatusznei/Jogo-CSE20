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
	const string tex_plataforma = "res/plataforma.png";

	const string tex_mumia = "res/mumia.png";

	const float pixel_scale = 2;
	const int block_size = 16;
}

namespace Fisica {
	const float G = 300;
	const float velocidade_terminal = 800;

	const float desaceleracao_jogador = 500;
	const float aceleracao_jogador = 340;
	const float max_vx_jogador = 160;
	const float v0_pulo_jogador = 205;
	const float vmin_pulo_jogador = 100;
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
