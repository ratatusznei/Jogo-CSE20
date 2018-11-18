/*
	Coisas comuns a todos os arquivos
*/

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
	const float G = 600;
	const float velocidade_terminal = 800;
}

namespace ConstsPersonagens {
	// Jogadores
	const float J_desaceleracao = 500;
	const float J_aceleracao = 340;
	const float J_max_vx = 160;
	const float J_v0_pulo = 305;
	const float J_vmin_pulo = 100;
	const float J_tempo_imunidade = 0.7;

	// Mumia
	const float M_desaceleracao = 500;
	const float M_aceleracao = 300;
	const float M_max_vx = 40;
	const float M_v_pulo = J_v0_pulo;
	const float M_distancia_deteccao = 120;

}

enum class EstadoApp {
	Nenhum = 0,
	Menu,
	Iniciar_jogo_solo,
	Iniciar_jogo_coop,
	Jogo,
	Tela_de_creditos,
	Sair,
};

enum class Direcao {
	Esquerda = -1,
	Direita = 1,
};

enum class TipoInimigo{
    _Mumia = 0,
    _Bad_Robot,
    _Cobra,
    _Hieracosphinx,
};

#endif // COMMON_H_INCLUDED
