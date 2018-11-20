#include "Farao.h"

const int F_total_anims = 4;
const int F_anim_parado = 0;
const int F_anim_pulando = 1;
const int F_anim_atacando = 2;
const int F_anim_andando = 3;

Farao::Farao(Jogador *j1, Jogador *j2, Lista<Projetil*>* projeteis, int x, int y):
Inimigo(x, y, projeteis, F_total_anims){
    _sp.setTexture(*GerenciadorDeTexturas::GetInstance()->GetFarao());

	_j1 = j1;
	_j2 = j2;
	_estado = EstadoFarao::Esperando;

	_max_vx = ConstsPersonagens::M_max_vx;
	_max_vy = Fisica::velocidade_terminal;

	_aceleracao_caminhada = ConstsPersonagens::M_aceleracao * 0.2;
	_desaceleracao = ConstsPersonagens::M_desaceleracao * 0.2;

	_velocidade_pulo = ConstsPersonagens::M_v_pulo * 1.1;

	_range = ConstsPersonagens::M_distancia_deteccao * 4;
	_range_ataque = 400;

	_x0 = x;
	_vida = 10;

	_animador.SetTextureBox(&_tex_rect);
	_animador.SetSprite(&_sp);
	_animador.SetTamanhoQuadro(Resources::block_size);

	_animador.SetOffSetY(0);
	_animador.SetPeriodo(0.1);

	_animador.SetFrameCount(F_anim_parado, 1);
	_animador.SetFrameCount(F_anim_pulando, 1);
	_animador.SetFrameCount(F_anim_atacando, 2);
	_animador.SetFrameCount(F_anim_andando, 2);

	_projetil_protipo.SetTexture(GerenciadorDeTexturas::GetInstance()->GetFarao());
	_projetil_protipo.SetTempoPraMorrer(1.5);
	_projetil_protipo.SetOffSetY(F_total_anims * Resources::block_size);
	_vx_ataque = 300;

	_timerDescanso = -1;
}

Farao::~Farao(){

}

void Farao::Executar(float dt){
	if (_posicao.y + _sp.getGlobalBounds().height > Janela::altura) {
		_vida = -1;
	}

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

	int delta_x = 50;
    switch (_estado) {
    case EstadoFarao::Esperando:
        _animador.Play(F_anim_andando);
        _animador.SetLoop(true);

		if (!_esta_no_chao) {
			_estado = EstadoFarao::Pulando;
		}

		if (_posicao.x > _x0 && _posicao.x - _x0 >= delta_x) {
			Acelerar(dt, -_aceleracao_caminhada);
		}
		else if (_posicao.x < _x0 && _x0 - _posicao.x >= delta_x) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (_velocidade.x > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else {
			Acelerar(dt, -_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			if (_batendo_esquerda || _batendo_direta) {
				_estado = EstadoFarao::Pulando;
				_velocidade.y = -_velocidade_pulo;
			}
		}

		if (_j1 != NULL) {
			if (mag_dist_j1 < _range && mag_dist_j1 < mag_dist_j2) {
				_estado = EstadoFarao::SeguindoJ1;
			}
		}

		if (_j2 != NULL) {
			if (mag_dist_j2 < _range && mag_dist_j2 < mag_dist_j1) {
				_estado = EstadoFarao::SeguindoJ2;
			}
		}
		break;

	case EstadoFarao::SeguindoJ1:
		_animador.Play(F_anim_andando);
		_animador.SetLoop(true);

		if (!_esta_no_chao) {
			_estado = EstadoFarao::Pulando;
		}
		else if (mag_dist_j1 < _range_ataque && _podeAtacar) {
			_estado = EstadoFarao::Atacando;
		}
		else if (_j2 != NULL && mag_dist_j2 < _range && mag_dist_j2 < mag_dist_j1) {
			_estado = EstadoFarao::SeguindoJ2;
		}
		else if (mag_dist_j1 > _range) {
			_estado = EstadoFarao::Esperando;
		}
		else if (dist_j1 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j1 < 0) {
			Acelerar(dt,-_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			if (_batendo_esquerda || _batendo_direta) {
				_estado = EstadoFarao::PulandoParaJ1;
				_velocidade.y = -_velocidade_pulo;
			}
		}
		break;

	case EstadoFarao::SeguindoJ2:
		_animador.Play(F_anim_andando);
		_animador.SetLoop(true);

		if (!_esta_no_chao) {
			_estado = EstadoFarao::Pulando;
		}
		else if (mag_dist_j2 < _range_ataque && _podeAtacar) {
			_estado = EstadoFarao::Atacando;
		}
		else if (_j1 != NULL && mag_dist_j1 < _range && mag_dist_j1 < mag_dist_j2) {
			_estado = EstadoFarao::SeguindoJ1;
		}
		else if (mag_dist_j2 > _range) {
			_estado = EstadoFarao::Esperando;
		}
		else if (dist_j2 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j2 < 0) {
			Acelerar(dt, -_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			if (_batendo_esquerda || _batendo_direta) {
				_estado = EstadoFarao::PulandoParaJ2;
				_velocidade.y = -_velocidade_pulo;
			}
		}
		break;

	case EstadoFarao::Pulando:
		_animador.Play(F_anim_pulando);
		_animador.SetLoop(false);

		if (_esta_no_chao) {
			_estado = EstadoFarao::Esperando;
		}
		break;

	case EstadoFarao::PulandoParaJ1:
		_animador.Play(F_anim_pulando);
		_animador.SetLoop(false);

		if (dist_j1 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j1 < 0) {
			Acelerar(dt,-_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			_estado = EstadoFarao::Esperando;
		}
		break;

	case EstadoFarao::PulandoParaJ2:
		_animador.Play(F_anim_pulando);
		_animador.SetLoop(false);

		if (dist_j2 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j2 < 0) {
			Acelerar(dt,-_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			_estado = EstadoFarao::Esperando;
		}
		break;

	case EstadoFarao::Atacando:
		_animador.Play(F_anim_atacando);
		_animador.SetLoop(false);

        _velocidade.x = 0;

		if (_podeAtacar) {
			Atacar();
			_timerDescanso = 3;
			_podeAtacar = false;
		}

		if (_animador.GetTerminou()) {
			if (mag_dist_j1 < _range) {
				_estado = EstadoFarao::SeguindoJ1;
			}
			else if (mag_dist_j2 < _range) {
				_estado = EstadoFarao::SeguindoJ2;
			}
			else {
				_estado = EstadoFarao::Esperando;
			}
		}
		break;

	default:
		_estado = EstadoFarao::Esperando;
	}

	if (_timerDescanso > 0) {
		_timerDescanso -= dt;
		_podeAtacar = false;
    }
	else {
		_podeAtacar = true;
	}

	AtualizarFisica(dt);
	_animador.Executar(dt);
}

bool Farao::PodeMachucar(){
	return true;
}
