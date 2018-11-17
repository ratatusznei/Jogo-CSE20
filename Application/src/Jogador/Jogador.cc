#include "Jogador.h"

int total_anims = 4;
int anim_parado = 0;
int anim_pulando = 1;
int anim_atacando = 2;
int anim_andando = 3;

Jogador::Jogador (GerenciadorDeInput *inputs, int x, int y):
Personagem(x, y, Resources::tex_jogador, total_anims),
_inputs(inputs)
{
}

Jogador::~Jogador () {
	delete _inputs;
}

void Jogador::IniciarRobo () {
	_max_vx = ConstsPersonagens::J_max_vx;
	_max_vy = Fisica::velocidade_terminal;

	_aceleracao_caminhada = ConstsPersonagens::J_aceleracao;
	_desaceleracao = ConstsPersonagens::J_desaceleracao;

	_velocidade_pulo = ConstsPersonagens::J_v0_pulo;
	_vmin_pulo = ConstsPersonagens::J_vmin_pulo;

	_animador.SetTextureBox(&_tex_rect);
	_animador.SetSprite(&_sp);
	_animador.SetTamanhoQuadro(Resources::block_size);

	_animador.SetOffSetY(0);
	_animador.SetPeriodo(0.1);

	_animador.SetFrameCount(anim_parado, 1);
	_animador.SetFrameCount(anim_pulando, 1);
	_animador.SetFrameCount(anim_atacando, 3);
	_animador.SetFrameCount(anim_andando, 2);
}

void Jogador::IniciarDoctor () {
	_max_vx = ConstsPersonagens::J_max_vx;
	_max_vy = Fisica::velocidade_terminal;

	_aceleracao_caminhada = ConstsPersonagens::J_aceleracao;
	_desaceleracao = ConstsPersonagens::J_desaceleracao;

	_velocidade_pulo = ConstsPersonagens::J_v0_pulo;
	_vmin_pulo = ConstsPersonagens::J_vmin_pulo;

	_animador.SetTextureBox(&_tex_rect);
	_animador.SetSprite(&_sp);
	_animador.SetTamanhoQuadro(Resources::block_size);

	_animador.SetOffSetY(Resources::block_size * total_anims);
	_animador.SetPeriodo(0.1);

	_animador.SetFrameCount(anim_parado, 1);
	_animador.SetFrameCount(anim_pulando, 1);
	_animador.SetFrameCount(anim_atacando, 1);
	_animador.SetFrameCount(anim_andando, 2);
}

void Jogador::Executar (float dt) {
	_inputs->Atualizar();

	/****  Temporario ****/
	if (_posicao.y + _sp.getGlobalBounds().height > Janela::altura) {
		_posicao.y = 0;
	}
	/****  Temporario/ ****/

	switch (_estado) {
	case EstadoJogador::Parado:
		_velocidade.y = 0;

		_animador.Play(anim_parado);
		_animador.SetLoop(false);

		Desacelerar(dt, _desaceleracao);

		if (!_esta_no_chao) {
			_estado = EstadoJogador::Pulando;
		}
		else if (_inputs->GetDireita() != _inputs->GetEsquerda()) {
			_estado = EstadoJogador::Andando;
		}
		else if (_inputs->GetAtacou()) {
			_estado = EstadoJogador::Atacando;
		}
		else if (_inputs->GetPulou()) {
			_velocidade.y = -_velocidade_pulo;
			_esta_no_chao = false;
			_estado = EstadoJogador::Pulando;
		}
		else if (_inputs->GetAtacou()) {
			_velocidade.x = 0;
			_estado = EstadoJogador::Atacando;
		}

		break;

	case EstadoJogador::Andando:
		_velocidade.y = 0;

		_animador.Play(anim_andando);
		_animador.SetLoop(true);

		if (!_esta_no_chao) {
			_estado = EstadoJogador::Pulando;
		}

		if (_inputs->GetDireita() == _inputs->GetEsquerda()) {
			_estado = EstadoJogador::Parado;
		}
		else if (_inputs->GetEsquerda()) {
			Acelerar(dt, -_aceleracao_caminhada);
		}
		else if (_inputs->GetDireita()) {
			Acelerar(dt, _aceleracao_caminhada);
		}

		if (_inputs->GetPulou()) {
			_velocidade.y = -_velocidade_pulo;
			_esta_no_chao = false;
			_estado = EstadoJogador::Pulando;
		}
		else if (_inputs->GetAtacou()) {
			_velocidade.x = 0;
			_estado = EstadoJogador::Atacando;
		}

		break;

	case EstadoJogador::Pulando:
		_aceleracao.y = Fisica::G;

		_animador.Play(anim_pulando);
		_animador.SetLoop(false);

		// Salta mais alto quando pressionar o botar mais tempo
		if (!_inputs->GetPulando() && _velocidade.y < 0) {
			if (-_velocidade.y > _vmin_pulo) {
				_velocidade.y = -_vmin_pulo;
			}
		}

		if (_inputs->GetEsquerda() == _inputs->GetDireita()) {
			Desacelerar(dt, _desaceleracao);
		}
		else if (_inputs->GetEsquerda()) {
			Acelerar(dt, -_aceleracao_caminhada);
		}
		else if (_inputs->GetDireita()) {
			Acelerar(dt, _aceleracao_caminhada);
		}

		if (_esta_no_chao) {
			if (_inputs->GetEsquerda() == _inputs->GetDireita()) {
				_estado = EstadoJogador::Parado;
			}
			else if (_inputs->GetEsquerda() != _inputs->GetDireita()) {
				_estado = EstadoJogador::Andando;
			}
		}

		break;

	case EstadoJogador::Atacando:
		_animador.Play(anim_atacando);
		_animador.SetLoop(false);

		_velocidade.x = 0;

		if (_animador.GetTerminou()) {
			_estado = EstadoJogador::Parado;
		}
		break;

	case EstadoJogador::Machucado:
	default:
		_estado = EstadoJogador::Parado;
	}

	AtualizarFisica(dt);
	_animador.Executar(dt);
}

const sf::Vector2f Jogador::GetPosicao () {
	return _posicao;
}
