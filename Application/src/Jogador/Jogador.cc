#include "Jogador.h"

int total_anims = 4;
int anim_parado = 0;
int anim_pulando = 1;
int anim_atacando = 2;
int anim_andando = 3;

Jogador::Jogador (GerenciadorDeInput *inputs, Lista<Projetil*>* projeteis, int x, int y):
Personagem(x, y, projeteis, total_anims),
_inputs(inputs)
{
	_projetil_protipo.SetTexture(GerenciadorDeTexturas::GetInstance()->GetJogador());
	_sp.setTexture(*GerenciadorDeTexturas::GetInstance()->GetJogador());

	_podeAtacar = true;

	_vida = 3;
	_timerMachucado = -1;
}

Jogador::~Jogador () {
}

void Jogador::IniciarRobo () {
	_podeAtacar = true;

	_velocidade.x = 0;
	_velocidade.y = 0;

	_vida = 3;
	_timerMachucado = -1;

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

	_projetil_protipo.SetTempoPraMorrer(0.3);
	_projetil_protipo.SetOffSetY((2 * total_anims) * Resources::block_size);
}

void Jogador::IniciarDoctor () {
	_podeAtacar = true;

	_velocidade.x = 0;
	_velocidade.y = 0;

	_vida = 3;
	_timerMachucado = -1;

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

	_vx_ataque = 600;
	_projetil_protipo.SetTempoPraMorrer(0.5);
	_projetil_protipo.SetOffSetY((2 * total_anims + 1) * Resources::block_size);
}

void Jogador::Machucar (int dano) {
	if (_timerMachucado < 0) {
		_vida -= dano;
		_velocidade.y = -_velocidade_pulo;;
		_esta_no_chao = false;

		_timerMachucado = ConstsPersonagens::J_tempo_imunidade;

		_estado = EstadoJogador::Pulando;
	}
}

void Jogador::Executar (float dt) {
	if (GetMorreu()) {
		SetPosicao(-666, 0);
	}
	else {
		_inputs->Atualizar();

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

			if (_podeAtacar) {
				Atacar();
				_podeAtacar = false;
			}

			if (_animador.GetTerminou()) {
				_estado = EstadoJogador::Parado;
				_podeAtacar = true;
			}
			break;

		default:
			_estado = EstadoJogador::Parado;
		}

		if (_posicao.y + _sp.getGlobalBounds().height > Janela::altura) {
			_vida = -1;
		}

		if (_posicao.x < 0) {
			_posicao.x = 0;

			if (_velocidade.x < 0) {
				_velocidade.x = 0;
			}
		}

		if (_timerMachucado > 0) {
			_timerMachucado -= dt;
			_piscadorMachucado += dt;

			if (_piscadorMachucado > 0.2) {
				_piscadorMachucado = 0;
				_sp.setColor(sf::Color::White);
			}
			else if (_piscadorMachucado > 0.1){
				_sp.setColor(sf::Color::Red);
			}
		}
		else {
			_sp.setColor(sf::Color::White);
		}

		AtualizarFisica(dt);
		_animador.Executar(dt);
	}
}


