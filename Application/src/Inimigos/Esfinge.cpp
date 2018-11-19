#include "Esfinge.h"

const int E_total_anims = 4;
const int E_anim_parado = 0;
const int E_anim_atacando = 1;
const int E_anim_guardando = 2;
const int E_anim_andando = 3;

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

	_x0 = x;
	_vida = 10;

	_animador.SetTextureBox(&_tex_rect);
	_animador.SetSprite(&_sp);
	_animador.SetTamanhoQuadro(Resources::block_size);

	_animador.SetOffSetY(0);
	_animador.SetPeriodo(0.1);

	_animador.SetFrameCount(E_anim_parado, 1);
	_animador.SetFrameCount(E_anim_andando, 2);
	_animador.SetFrameCount(E_anim_atacando, 2);
	_animador.SetFrameCount(E_anim_guardando, 1);
    
}

Esfinge::~Esfinge(){}

void Esfinge::Executar(float dt){

	/****  Temporario ****/
	if (_posicao.y + _sp.getGlobalBounds().height > Janela::altura) {
		_posicao.y = 0;
	}
	/****  Temporario/ ****/

	float dist_j1;
	float dist_j2;
	float mag_dist_j1;
	float mag_dist_j2;
	
	if (_j1 != NULL) {
		dist_j1 = _j1->GetPosicao().x - _posicao.x;
		mag_dist_j1 = dist_j1 > 0? dist_j1: -dist_j1;
	}
	if (_j2 != NULL) {
		dist_j2 = _j2->GetPosicao().x - _posicao.x;
		mag_dist_j2 = dist_j2 > 0? dist_j2: -dist_j2;
	}

	if (!_esta_no_chao) {
		_aceleracao.y = Fisica::G;
	}
	else {
		_aceleracao.y = 0;
	}
	
	switch(_estado){
	case EstadoEsfinge::Esperando:
		_animador.Play(E_anim_parado);
		_animador.SetLoop(true);
		if(!_esta_no_chao){
			_estado = EstadoEsfinge::Pulando;
			
		
		
	}

}
	
bool Esfinge::PodeMachucar(){
	if(_estado == EstadoEsfinge::Guardando){
		return true;
	}
	else{
		return false;
	}
}
