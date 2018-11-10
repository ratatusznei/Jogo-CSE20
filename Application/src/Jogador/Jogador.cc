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
}

Jogador::~Jogador () {
	delete _inputs;
}

void Jogador::Executar () {
	_inputs->Atualizar();

	_aceleracao.x = 0;
	_aceleracao.y = 0;

	if (_posicao.y + _sp.getGlobalBounds().height > Janela::altura) {
		_esta_no_chao = true;
		_posicao.y = Janela::altura - _sp.getGlobalBounds().height;
	}

	switch (_estado) {
	case EstadoJogador::Parado:
		_velocidade.x = 0;
		_velocidade.y = 0;

		if (!_esta_no_chao) {
			_estado = EstadoJogador::Pulando;
		}
		else if (_inputs->GetDireita() != _inputs->GetEsquerda()) {
			_estado = EstadoJogador::Andando;
		}
		else if (_inputs->GetAtaque()) {
			_estado = EstadoJogador::Atacando;
		}
		else if (_inputs->GetPulo()) {
			_velocidade.y = -Fisica::velocidade_pulo_jogador;
			_esta_no_chao = false;
			_estado = EstadoJogador::Pulando;
		}

		break;

	case EstadoJogador::Andando:
		if (_inputs->GetDireita() == _inputs->GetEsquerda()) {
			_estado = EstadoJogador::Parado;
		}
		else if (_inputs->GetEsquerda()) {
			_velocidade.x = -Fisica::velocidade_max_jogador;
		}
		else if (_inputs->GetDireita()) {
			_velocidade.x = Fisica::velocidade_max_jogador;
		}

		if (_inputs->GetPulo()) {
			_velocidade.y = -Fisica::velocidade_pulo_jogador;
			_esta_no_chao = false;
			_estado = EstadoJogador::Pulando;
		}

		break;

	case EstadoJogador::Pulando:
		_velocidade.y += Fisica::G;

		if (_velocidade.y > Fisica::velocidade_terminal) {
			_velocidade.y = Fisica::velocidade_terminal;
		}

		if (_inputs->GetEsquerda() == _inputs->GetDireita()) {
			_velocidade.x = 0;
		}
		else if (_inputs->GetEsquerda()) {
			_velocidade.x = -Fisica::velocidade_max_jogador;
		}
		else if (_inputs->GetDireita()) {
			_velocidade.x = Fisica::velocidade_max_jogador;
		}

		if (_esta_no_chao) {
			_estado = EstadoJogador::Parado;
		}

		break;

	case EstadoJogador::Atacando:
	case EstadoJogador::Machucado:
	default:
		_estado = EstadoJogador::Parado;
	}

	Mover();
}
