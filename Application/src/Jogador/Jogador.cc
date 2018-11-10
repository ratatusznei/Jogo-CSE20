#include "Jogador.h"

Jogador::Jogador ():
_tex_rect(0, 0, 16, 16)
{
	_tex.loadFromFile(Resources::tex_jogador);
	_sp.setTexture(_tex);

	_sp.setPosition(_posicao);
	_sp.setTextureRect(_tex_rect);
	_sp.setScale(4, 4);

	_no_chao = false;
}

Jogador::~Jogador () {
	//dtor
}

void Jogador::SetGerenciadorDeInput (GerenciadorDeInput *inputs) {
	_inputs = inputs;
}

void Jogador::Machucar (int dano) {
	_vida -= dano;
}

void Jogador::Mover () {

}

void Jogador::Executar () {
	float dt = GerenciadorGrafico::GetInstance()->GetDeltaTime();

	_posicao += _velocidade * dt;
	_velocidade += _aceleracao * dt;
	_aceleracao.x = 0;
	_aceleracao.y = 0;

	_sp.setPosition(_posicao);

	if (_posicao.y + _sp.getGlobalBounds().height > Janela::altura) {
		_no_chao = true;
		_posicao.y = Janela::altura - _sp.getGlobalBounds().height;
	}

	switch (_estado) {
	case EstadoJogador::Parado:
		_velocidade.x = 0;
		_velocidade.y = 0;

		if (!_no_chao) {
			_estado = EstadoJogador::Pulando;
		}
		else if (_inputs->GetDireita() != _inputs->GetEsquerda()) {
			_estado = EstadoJogador::Andando;
		}
		else if (_inputs->GetAtaque()) {
			_estado = EstadoJogador::Atacando;
		}
		else if (_inputs->GetPulo()) {
			_velocidade.y = -Propriedades::velocidade_pulo_jogador;
			_no_chao = false;
			_estado = EstadoJogador::Pulando;
		}

		break;

	case EstadoJogador::Andando:
		if (_inputs->GetDireita() == _inputs->GetEsquerda()) {
			_estado = EstadoJogador::Parado;
		}
		else if (_inputs->GetEsquerda()) {
			_velocidade.x = -Propriedades::velocidade_max_jogador;
		}
		else if (_inputs->GetDireita()) {
			_velocidade.x = Propriedades::velocidade_max_jogador;
		}

		if (_inputs->GetPulo()) {
			_velocidade.y = -Propriedades::velocidade_pulo_jogador;
			_no_chao = false;
			_estado = EstadoJogador::Pulando;
		}

		break;

	case EstadoJogador::Pulando:
		_velocidade.y += Propriedades::G;

		if (_velocidade.y > Propriedades::velocidade_terminal) {
			_velocidade.y = Propriedades::velocidade_terminal;
		}

		if (_inputs->GetEsquerda() == _inputs->GetDireita()) {
			_velocidade.x = 0;
		}
		else if (_inputs->GetEsquerda()) {
			_velocidade.x = -Propriedades::velocidade_max_jogador;
		}
		else if (_inputs->GetDireita()) {
			_velocidade.x = Propriedades::velocidade_max_jogador;
		}

		if (_no_chao) {
			_estado = EstadoJogador::Parado;
		}

		break;

	case EstadoJogador::Atacando:
	case EstadoJogador::Machucado:
	default:
		_estado = EstadoJogador::Parado;
	}
}

void Jogador::Desenhar () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();

	janela->Desenhar(_sp);
}
