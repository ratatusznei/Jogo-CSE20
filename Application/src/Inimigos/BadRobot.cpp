#include "BadRobot.h"

const int R_total_anims = 4;
const int R_anim_parado = 0;
const int R_anim_pulando = 1;
const int R_anim_atacando = 2;
const int R_anim_andando = 3;

BadRobot::BadRobot(Jogador *j1, Jogador *j2, Lista<Projetil*>* projeteis, int x, int y):
Inimigo(x, y, projeteis, R_total_anims) {
	_sp.setTexture(*GerenciadorDeTexturas::GetInstance()->GetBRobot());

	_j1 = j1;
	_j2 = j2;
	_estado = EstadoBRobot::Perdido;

	_maxVx = ConstsPersonagens::M_maxVx;
	_maxVy = Fisica::velocidade_terminal;

	_aceleracaoCaminhada = ConstsPersonagens::M_aceleracao * 1.2;
	_desaceleracao = ConstsPersonagens::M_desaceleracao * 1.2;

	_velocidadePulo = ConstsPersonagens::M_v_pulo;

	_range = ConstsPersonagens::M_distancia_deteccao * 2;
	_rangeAtaque = 30;

	_x0 = x;

	_animador.SetTextureBox(&_texRect);
	_animador.SetSprite(&_sp);
	_animador.SetTamanhoQuadro(Resources::block_size);

	_animador.SetOffSetY(0);
	_animador.SetPeriodo(0.1);

	_animador.SetFrameCount(R_anim_parado, 1);
	_animador.SetFrameCount(R_anim_pulando, 1);
	_animador.SetFrameCount(R_anim_atacando, 2);
	_animador.SetFrameCount(R_anim_andando, 2);
}

BadRobot::~BadRobot() {
	//dtor
}

void BadRobot::Executar (float dt) {
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

	if (!_estaNoChao) {
		_aceleracao.y = Fisica::G;
	}
	else {
		_aceleracao.y = 0;
	}

	int delta_x = 50;
    switch (_estado) {
    case EstadoBRobot::Perdido:
		_animador.Play(R_anim_andando);
		_animador.SetLoop(true);

		if (!_estaNoChao) {
			_estado = EstadoBRobot::Pulando;
		}

		if (_posicao.x > _x0 && _posicao.x - _x0 >= delta_x) {
			Acelerar(dt, -_aceleracaoCaminhada);
		}
		else if (_posicao.x < _x0 && _x0 - _posicao.x >= delta_x) {
			Acelerar(dt, _aceleracaoCaminhada);
		}
		else if (_velocidade.x > 0) {
			Acelerar(dt, _aceleracaoCaminhada);
		}
		else {
			Acelerar(dt, -_aceleracaoCaminhada);
		}

		if (_estaNoChao) {
			if (_batendoEsquerda || _batendoDireta) {
				_estado = EstadoBRobot::Pulando;
				_velocidade.y = -_velocidadePulo;
			}
		}

		if (_j1 != NULL) {
			if (mag_dist_j1 < _range && mag_dist_j1 < mag_dist_j2) {
				_estado = EstadoBRobot::SeguindoJ1;
			}
		}

		if (_j2 != NULL) {
			if (mag_dist_j2 < _range && mag_dist_j2 < mag_dist_j1) {
				_estado = EstadoBRobot::SeguindoJ2;
			}
		}
		break;

	case EstadoBRobot::SeguindoJ1:
		_animador.Play(R_anim_andando);
		_animador.SetLoop(true);

		if (!_estaNoChao) {
			_estado = EstadoBRobot::Pulando;
		}
		else if (mag_dist_j1 < _rangeAtaque) {
			_estado = EstadoBRobot::Atacando;
		}
		else if (_j2 != NULL && mag_dist_j2 < _range && mag_dist_j2 < mag_dist_j1) {
			_estado = EstadoBRobot::SeguindoJ2;
		}
		else if (mag_dist_j1 > _range) {
			_estado = EstadoBRobot::Perdido;
		}
		else if (dist_j1 > 0) {
			Acelerar(dt, _aceleracaoCaminhada);
		}
		else if (dist_j1 < 0) {
			Acelerar(dt,-_aceleracaoCaminhada);
		}

		if (_estaNoChao) {
			if (_batendoEsquerda || _batendoDireta) {
				_estado = EstadoBRobot::PulandoParaJ1;
				_velocidade.y = -_velocidadePulo;
			}
		}
		break;

	case EstadoBRobot::SeguindoJ2:
		_animador.Play(R_anim_andando);
		_animador.SetLoop(true);

		if (!_estaNoChao) {
			_estado = EstadoBRobot::Pulando;
		}
		else if (mag_dist_j2 < _rangeAtaque) {
			_estado = EstadoBRobot::Atacando;
		}
		else if (_j1 != NULL && mag_dist_j1 < _range && mag_dist_j1 < mag_dist_j2) {
			_estado = EstadoBRobot::SeguindoJ1;
		}
		else if (mag_dist_j2 > _range) {
			_estado = EstadoBRobot::Perdido;
		}
		else if (dist_j2 > 0) {
			Acelerar(dt, _aceleracaoCaminhada);
		}
		else if (dist_j2 < 0) {
			Acelerar(dt, -_aceleracaoCaminhada);
		}

		if (_estaNoChao) {
			if (_batendoEsquerda || _batendoDireta) {
				_estado = EstadoBRobot::PulandoParaJ2;
				_velocidade.y = -_velocidadePulo;
			}
		}
		break;

	case EstadoBRobot::Pulando:
		_animador.Play(R_anim_pulando);
		_animador.SetLoop(false);

		if (_estaNoChao) {
			_estado = EstadoBRobot::Perdido;
		}
		break;

	case EstadoBRobot::PulandoParaJ1:
		_animador.Play(R_anim_pulando);
		_animador.SetLoop(false);

		if (dist_j1 > 0) {
			Acelerar(dt, _aceleracaoCaminhada);
		}
		else if (dist_j1 < 0) {
			Acelerar(dt,-_aceleracaoCaminhada);
		}

		if (_estaNoChao) {
			_estado = EstadoBRobot::Perdido;
		}
		break;

	case EstadoBRobot::PulandoParaJ2:
		_animador.Play(R_anim_pulando);
		_animador.SetLoop(false);

		if (dist_j2 > 0) {
			Acelerar(dt, _aceleracaoCaminhada);
		}
		else if (dist_j2 < 0) {
			Acelerar(dt,-_aceleracaoCaminhada);
		}

		if (_estaNoChao) {
			_estado = EstadoBRobot::Perdido;
		}
		break;

	case EstadoBRobot::Atacando:
		_animador.Play(R_anim_atacando);
		_animador.SetLoop(false);

		_velocidade.x = 0;

		if (_animador.GetTerminou()) {
			if (mag_dist_j1 < _rangeAtaque || mag_dist_j2 < _rangeAtaque) {
				_estado = EstadoBRobot::Atacando;
				_animador.Restart();
			}
			else if (mag_dist_j1 < _range) {
				_estado = EstadoBRobot::SeguindoJ1;
			}
			else if (mag_dist_j2 < _range) {
				_estado = EstadoBRobot::SeguindoJ2;
			}
			else {
				_estado = EstadoBRobot::Perdido;
			}
		}
		break;

	default:
		_estado = EstadoBRobot::Perdido;
	}

	AtualizarFisica(dt);
	_animador.Executar(dt);
}

