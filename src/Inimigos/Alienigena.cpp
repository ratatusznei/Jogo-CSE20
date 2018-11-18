#include "Alienigena.h"

const int A_total_anims = 4;
const int A_anim_parado = 0;
const int A_anim_pulando = 1;
const int A_anim_atacando = 2;
const int A_anim_andando = 3;

Alienigena::Alienigena(Jogador *j1, Jogador *j2, Lista<Projetil*>* projeteis, int x, int y):
Inimigo(x, y, projeteis, A_total_anims) {
	_sp.setTexture(*GerenciadorDeTexturas::GetInstance()->GetAlien());

	_j1 = j1;
	_j2 = j2;
	_estado = EstadoAlien::Perdido;

	_max_vx = ConstsPersonagens::M_max_vx;
	_max_vy = Fisica::velocidade_terminal;

	_aceleracao_caminhada = ConstsPersonagens::M_aceleracao * 1.2;
	_desaceleracao = ConstsPersonagens::M_desaceleracao * 1.2;

	_velocidade_pulo = ConstsPersonagens::M_v_pulo;

	_range = ConstsPersonagens::M_distancia_deteccao * 10;
	_range_ataque = 300;

	_x0 = x;

	_animador.SetTextureBox(&_tex_rect);
	_animador.SetSprite(&_sp);
	_animador.SetTamanhoQuadro(Resources::block_size);

	_animador.SetOffSetY(0);
	_animador.SetPeriodo(0.1);

	_animador.SetFrameCount(A_anim_parado, 1);
	_animador.SetFrameCount(A_anim_pulando, 1);
	_animador.SetFrameCount(A_anim_atacando, 2);
	_animador.SetFrameCount(A_anim_andando, 2);
}

Alienigena::~Alienigena() {
	//dtor
}

void Alienigena::Executar (float dt) {
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

	int delta_x = 50;
        switch (_estado) {
        case EstadoAlien::Perdido:
		_animador.Play(A_anim_andando);
		_animador.SetLoop(true);

		if (!_esta_no_chao) {
			_estado = EstadoAlien::Pulando;
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
				_estado = EstadoAlien::Pulando;
				_velocidade.y = -_velocidade_pulo;
			}
		}

		if (_j1 != NULL) {
			if (mag_dist_j1 < _range && mag_dist_j1 < mag_dist_j2) {
				_estado = EstadoAlien::SeguindoJ1;
			}
		}

		if (_j2 != NULL) {
			if (mag_dist_j2 < _range && mag_dist_j2 < mag_dist_j1) {
				_estado = EstadoAlien::SeguindoJ2;
			}
		}
		break;

	case EstadoAlien::SeguindoJ1:
		_animador.Play(A_anim_andando);
		_animador.SetLoop(true);

		if (!_esta_no_chao) {
			_estado = EstadoAlien::Pulando;
		}
		else if (mag_dist_j1 < _range_ataque) {
			_estado = EstadoAlien::Atacando;
		}
		else if (_j2 != NULL && mag_dist_j2 < _range && mag_dist_j2 < mag_dist_j1) {
			_estado = EstadoAlien::SeguindoJ2;
		}
		else if (mag_dist_j1 > _range) {
			_estado = EstadoAlien::Perdido;
		}
		else if (dist_j1 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j1 < 0) {
			Acelerar(dt,-_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			if (_batendo_esquerda || _batendo_direta) {
				_estado = EstadoAlien::PulandoParaJ1;
				_velocidade.y = -_velocidade_pulo;
			}
		}
		break;

	case EstadoAlien::SeguindoJ2:
		_animador.Play(A_anim_andando);
		_animador.SetLoop(true);

		if (!_esta_no_chao) {
			_estado = EstadoAlien::Pulando;
		}
		else if (mag_dist_j2 < _range_ataque) {
			_estado = EstadoAlien::Atacando;
		}
		else if (_j1 != NULL && mag_dist_j1 < _range && mag_dist_j1 < mag_dist_j2) {
			_estado = EstadoAlien::SeguindoJ1;
		}
		else if (mag_dist_j2 > _range) {
			_estado = EstadoAlien::Perdido;
		}
		else if (dist_j2 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j2 < 0) {
			Acelerar(dt, -_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			if (_batendo_esquerda || _batendo_direta) {
				_estado = EstadoAlien::PulandoParaJ2;
				_velocidade.y = -_velocidade_pulo;
			}
		}
		break;

	case EstadoAlien::Pulando:
		_animador.Play(A_anim_pulando);
		_animador.SetLoop(false);

		if (_esta_no_chao) {
			_estado = EstadoAlien::Perdido;
		}
		break;

	case EstadoAlien::PulandoParaJ1:
		_animador.Play(A_anim_pulando);
		_animador.SetLoop(false);

		if (dist_j1 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j1 < 0) {
			Acelerar(dt,-_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			_estado = EstadoAlien::Perdido;
		}
		break;

	case EstadoAlien::PulandoParaJ2:
		_animador.Play(A_anim_pulando);
		_animador.SetLoop(false);

		if (dist_j2 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j2 < 0) {
			Acelerar(dt,-_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			_estado = EstadoAlien::Perdido;
		}
		break;

	case EstadoAlien::Atacando:
		_animador.Play(A_anim_atacando);
		_animador.SetLoop(false);

		_velocidade.x = 0;

		if (_animador.GetTerminou()) {
			if (mag_dist_j1 < _range_ataque || mag_dist_j2 < _range_ataque) {
				_estado = EstadoAlien::Atacando;
				_animador.Restart();
			}
			else if (mag_dist_j1 < _range) {
				_estado = EstadoAlien::SeguindoJ1;
			}
			else if (mag_dist_j2 < _range) {
				_estado = EstadoAlien::SeguindoJ2;
			}
			else {
				_estado = EstadoAlien::Perdido;
			}
		}
		break;

	default:
		_estado = EstadoAlien::Perdido;
	}

	AtualizarFisica(dt);
	_animador.Executar(dt);
}

