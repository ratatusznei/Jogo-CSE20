#include "Mumia.h"

Mumia::Mumia(Jogador *j1, Jogador *j2, int x, int y):
Inimigo(x, y, Resources::tex_mumia) {
	_j1 = j1;
	_j2 = j2;
	_estado = EstadoMumia::Perdida;

	_max_vx = max_vx_mumia;
	_max_vy = max_vy_mumia;

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
			Acelerar(dt, -aceleracao_mumia);
		}
		else if (_posicao.x < _x0 && _x0 - _posicao.x >= delta_x) {
			Acelerar(dt, aceleracao_mumia);
		}
		else if (_velocidade.x > 0) {
			Acelerar(dt, aceleracao_mumia);
		}
		else {
			Acelerar(dt, -aceleracao_mumia);
		}

		if (_esta_no_chao) {
			if (_batendo_esquerda || _batendo_direta) {
				_velocidade.y = -v_pulo_mumia;
			}
		}

		if (_j1 != NULL) {
			if (mag_dist_j1 < distancia_deteccao && mag_dist_j1 < mag_dist_j2) {
				_estado = EstadoMumia::SeguindoJ1;
			}
		}

		if (_j2 != NULL) {
			if (mag_dist_j2 < distancia_deteccao && mag_dist_j2 < mag_dist_j1) {
				_estado = EstadoMumia::SeguindoJ2;
			}
		}
		break;

	case EstadoMumia::SeguindoJ1:
		if (_j2 != NULL && mag_dist_j2 < distancia_deteccao && mag_dist_j2 < mag_dist_j1) {
			_estado = EstadoMumia::SeguindoJ2;
		}
		else if (mag_dist_j1 > distancia_deteccao) {
			_estado = EstadoMumia::Perdida;
		}
		else if (dist_j1 > 0) {
			Acelerar(dt, aceleracao_mumia);
		}
		else if (dist_j1 < 0) {
			Acelerar(dt,-aceleracao_mumia);
		}

		if (_esta_no_chao) {
			if (_batendo_esquerda || _batendo_direta) {
				_velocidade.y = -v_pulo_mumia;
			}
		}
		break;

	case EstadoMumia::SeguindoJ2:
		if (_j1 != NULL && mag_dist_j1 < distancia_deteccao && mag_dist_j1 < mag_dist_j2) {
			_estado = EstadoMumia::SeguindoJ1;
		}
		else if (mag_dist_j2 > distancia_deteccao) {
			_estado = EstadoMumia::Perdida;
		}
		else if (dist_j2 > 0) {
			Acelerar(dt, aceleracao_mumia);
		}
		else if (dist_j2 < 0) {
			Acelerar(dt, -aceleracao_mumia);
		}

		if (_esta_no_chao) {
			if (_batendo_esquerda || _batendo_direta) {
				_velocidade.y = -v_pulo_mumia;
			}
		}
		break;

	default:
		_estado = EstadoMumia::Perdida;
	}

	AtualizarFisica(dt);
}