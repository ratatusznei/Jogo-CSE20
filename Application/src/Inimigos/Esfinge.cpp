#include "Esfinge.h"

const int E_total_anims = 4;
const int E_anim_parado = 0;
const int E_anim_pulando = 1;
const int E_anim_atacando = 2;
const int E_anim_guardando = 3;

Esfinge::Esfinge(Jogador *j1, Jogador *j2, Lista<Projetil*>* projeteis, int x, int y):
Inimigo(x, y, projeteis, E_total_anims){
    _sp.setTexture(*GerenciadorDeTexturas::GetInstance()->GetEsfinge());

	_j1 = j1;
	_j2 = j2;
	_estado = EstadoEsfinge::Esperando;

	_max_vx = ConstsPersonagens::M_max_vx;
	_max_vy = Fisica::velocidade_terminal;

	_aceleracao_caminhada = ConstsPersonagens::M_aceleracao * 0.2;
	_desaceleracao = ConstsPersonagens::M_desaceleracao * 0.2;

	_velocidade_pulo = ConstsPersonagens::M_v_pulo * 1.1;

	_range = ConstsPersonagens::M_distancia_deteccao * 4;
	_range_ataque = 40;
    _range_dist = 150;

	_x0 = x;

	_animador.SetTextureBox(&_tex_rect);
	_animador.SetSprite(&_sp);
	_animador.SetTamanhoQuadro(Resources::block_size);

	_animador.SetOffSetY(0);
	_animador.SetPeriodo(0.1);

	_animador.SetFrameCount(E_anim_parado, 1);
	_animador.SetFrameCount(E_anim_pulando, 1);
	_animador.SetFrameCount(E_anim_atacando, 2);
	_animador.SetFrameCount(E_anim_guardando, 1);
    
}
