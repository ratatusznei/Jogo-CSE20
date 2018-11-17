#include "Mumia.h"

Mumia::Mumia(Jogador *j1, Jogador *j2, int x, int y):
Inimigo(x, y, Resources::tex_mumia) {
	_j1 = j1;
	_j2 = j2;
	_estado = EstadoMumia::Perdida;

	_max_vx = ConstsPersonagens::M_max_vx;
	_max_vy = Fisica::velocidade_terminal;

	_aceleracao_caminhada = ConstsPersonagens::M_aceleracao;
	_desaceleracao = ConstsPersonagens::M_desaceleracao;

	_velocidade_pulo = ConstsPersonagens::M_v_pulo;

	_range = ConstsPersonagens::M_distancia_deteccao;

	_x0 = x;
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
		if (_j2 != NULL && mag_dist_j2 < _range && mag_dist_j2 < mag_dist_j1) {
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
				_velocidade.y = -_velocidade_pulo;
			}
		}
		break;

	case EstadoMumia::SeguindoJ2:
		if (_j1 != NULL && mag_dist_j1 < _range && mag_dist_j1 < mag_dist_j2) {
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
				_velocidade.y = -_velocidade_pulo;
			}
		}
		break;

	default:
		_estado = EstadoMumia::Perdida;
	}

	AtualizarFisica(dt);
}
