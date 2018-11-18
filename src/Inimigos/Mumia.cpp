#include "Mumia.h"

const int M_total_anims = 4;
const int M_anim_parado = 0;
const int M_anim_pulando = 1;
const int M_anim_atacando = 2;
const int M_anim_andando = 3;

Mumia::Mumia(Jogador *j1, Jogador *j2, Lista<Projetil*>* projeteis, int x, int y):
Inimigo(x, y, projeteis, M_total_anims) {
	_sp.setTexture(*GerenciadorDeTexturas::GetInstance()->GetMumia());

	_j1 = j1;
	_j2 = j2;
	_estado = EstadoMumia::Perdida;

	_max_vx = ConstsPersonagens::M_max_vx;
	_max_vy = Fisica::velocidade_terminal;

	_aceleracao_caminhada = ConstsPersonagens::M_aceleracao;
	_desaceleracao = ConstsPersonagens::M_desaceleracao;

	_velocidade_pulo = ConstsPersonagens::M_v_pulo;

	_range = ConstsPersonagens::M_distancia_deteccao;
	_range_ataque = 20;

	_x0 = x;

	_animador.SetTextureBox(&_tex_rect);
	_animador.SetSprite(&_sp);
	_animador.SetTamanhoQuadro(Resources::block_size);

	_animador.SetOffSetY(0);
	_animador.SetPeriodo(0.1);

	_animador.SetFrameCount(M_anim_parado, 1);
	_animador.SetFrameCount(M_anim_pulando, 1);
	_animador.SetFrameCount(M_anim_atacando, 2);
	_animador.SetFrameCount(M_anim_andando, 2);
}

Mumia::~Mumia() {
	//dtor
}

void Mumia::Executar (float dt) {
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
        case EstadoMumia::Perdida:
		_animador.Play(M_anim_andando);
		_animador.SetLoop(true);

		if (!_esta_no_chao) {
			_estado = EstadoMumia::Pulando;
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
				_estado = EstadoMumia::Pulando;
				_velocidade.y = -_velocidade_pulo;
			}
		}

		if (_j1 != NULL) {
			if (mag_dist_j1 < _range && mag_dist_j1 < mag_dist_j2) {
				_estado = EstadoMumia::SeguindoJ1;
			}
		}

		if (_j2 != NULL) {
			if (mag_dist_j2 < _range && mag_dist_j2 < mag_dist_j1) {
				_estado = EstadoMumia::SeguindoJ2;
			}
		}
		break;

	case EstadoMumia::SeguindoJ1:
		_animador.Play(M_anim_andando);
		_animador.SetLoop(true);

		if (!_esta_no_chao) {
			_estado = EstadoMumia::Pulando;
		}
		else if (mag_dist_j1 < _range_ataque) {
			_estado = EstadoMumia::Atacando;
		}
		else if (_j2 != NULL && mag_dist_j2 < _range && mag_dist_j2 < mag_dist_j1) {
			_estado = EstadoMumia::SeguindoJ2;
		}
		else if (mag_dist_j1 > _range) {
			_estado = EstadoMumia::Perdida;
		}
		else if (dist_j1 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j1 < 0) {
			Acelerar(dt,-_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			if (_batendo_esquerda || _batendo_direta) {
				_estado = EstadoMumia::PulandoParaJ1;
				_velocidade.y = -_velocidade_pulo;
			}
		}
		break;

	case EstadoMumia::SeguindoJ2:
		_animador.Play(M_anim_andando);
		_animador.SetLoop(true);

		if (!_esta_no_chao) {
			_estado = EstadoMumia::Pulando;
		}
		else if (mag_dist_j2 < _range_ataque) {
			_estado = EstadoMumia::Atacando;
		}
		else if (_j1 != NULL && mag_dist_j1 < _range && mag_dist_j1 < mag_dist_j2) {
			_estado = EstadoMumia::SeguindoJ1;
		}
		else if (mag_dist_j2 > _range) {
			_estado = EstadoMumia::Perdida;
		}
		else if (dist_j2 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j2 < 0) {
			Acelerar(dt, -_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			if (_batendo_esquerda || _batendo_direta) {
				_estado = EstadoMumia::PulandoParaJ2;
				_velocidade.y = -_velocidade_pulo;
			}
		}
		break;

	case EstadoMumia::Pulando:
		_animador.Play(M_anim_pulando);
		_animador.SetLoop(false);

		if (_esta_no_chao) {
			_estado = EstadoMumia::Perdida;
		}
		break;

	case EstadoMumia::PulandoParaJ1:
		_animador.Play(M_anim_pulando);
		_animador.SetLoop(false);

		if (dist_j1 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j1 < 0) {
			Acelerar(dt,-_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			_estado = EstadoMumia::Perdida;
		}
		break;

	case EstadoMumia::PulandoParaJ2:
		_animador.Play(M_anim_pulando);
		_animador.SetLoop(false);

		if (dist_j2 > 0) {
			Acelerar(dt, _aceleracao_caminhada);
		}
		else if (dist_j2 < 0) {
			Acelerar(dt,-_aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			_estado = EstadoMumia::Perdida;
		}
		break;

	case EstadoMumia::Atacando:
		_animador.Play(M_anim_atacando);
		_animador.SetLoop(false);

		_velocidade.x = 0;

		if (_animador.GetTerminou()) {
			if (mag_dist_j1 < _range_ataque || mag_dist_j2 < _range_ataque) {
				_estado = EstadoMumia::Atacando;
				_animador.Restart();
			}
			else if (mag_dist_j1 < _range) {
				_estado = EstadoMumia::SeguindoJ1;
			}
			else if (mag_dist_j2 < _range) {
				_estado = EstadoMumia::SeguindoJ2;
			}
			else {
				_estado = EstadoMumia::Perdida;
			}
		}
		break;

	default:
		_estado = EstadoMumia::Perdida;
	}

	AtualizarFisica(dt);
	_animador.Executar(dt);
}
