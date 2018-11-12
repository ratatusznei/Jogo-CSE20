#include "Jogador.h"

Jogador::Jogador (GerenciadorDeInput *inputs):
Personagem(0, 0, Resources::tex_jogador),
_inputs(inputs)
{
	_tex_rect.top = 0;
	_tex_rect.left = 0;
	_tex_rect.width = Resources::block_size;
	_tex_rect.height = Resources::block_size;
	_sp.setTextureRect(_tex_rect);

	_esta_no_chao = false;
	_max_vx = Fisica::max_vx_jogador;
	_max_vy = Fisica::velocidade_terminal;
}

Jogador::~Jogador () {
	delete _inputs;
}

void Jogador::Executar () {
	float dt = GerenciadorGrafico::GetInstance()->GetDeltaTime();
	_inputs->Atualizar();

	/****  Temporario ****/
	if (_posicao.y + _sp.getGlobalBounds().height > Janela::altura) {
		_posicao.y = 0;
	}
	/****  Temporario/ ****/

	switch (_estado) {
	case EstadoJogador::Parado:
		_velocidade.y = 0;

		Desacelerar(dt, Fisica::desaceleracao_jogador);

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
			_velocidade.y = -Fisica::v0_pulo_jogador;
			_esta_no_chao = false;
			_estado = EstadoJogador::Pulando;
		}

		break;

	case EstadoJogador::Andando:
		_velocidade.y = 0;

		if (!_esta_no_chao) {
			_estado = EstadoJogador::Pulando;
		}

		if (_inputs->GetDireita() == _inputs->GetEsquerda()) {
			_estado = EstadoJogador::Parado;
		}
		else if (_inputs->GetEsquerda()) {
			Acelerar(dt, -Fisica::aceleracao_jogador);
		}
		else if (_inputs->GetDireita()) {
			Acelerar(dt, Fisica::aceleracao_jogador);
		}

		if (_inputs->GetPulou()) {
			_velocidade.y = -Fisica::v0_pulo_jogador;
			_esta_no_chao = false;
			_estado = EstadoJogador::Pulando;
		}

		break;

	case EstadoJogador::Pulando:
		_aceleracao.y = Fisica::G;

		// Salta mais alto quando pressionar o botar mais tempo
		if (!_inputs->GetPulando() && _velocidade.y < 0) {
			if (-_velocidade.y > Fisica::vmin_pulo_jogador) {
				_velocidade.y = -Fisica::vmin_pulo_jogador;
			}
		}

		if (_inputs->GetEsquerda() == _inputs->GetDireita()) {
			Desacelerar(dt, Fisica::desaceleracao_jogador);
		}
		else if (_inputs->GetEsquerda()) {
			Acelerar(dt, -Fisica::aceleracao_jogador);
		}
		else if (_inputs->GetDireita()) {
			Acelerar(dt, Fisica::aceleracao_jogador);
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
	case EstadoJogador::Machucado:
	default:
		_estado = EstadoJogador::Parado;
	}

	AtualizarFisica(dt);
}
