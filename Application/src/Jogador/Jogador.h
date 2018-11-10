#ifndef JOGADOR_H
#define JOGADOR_H

#include "GerenciadorDeInput.h"
#include "../GerenciadorGrafico.h"
#include "../common.h"

class Jogador {
	public:
		Jogador();
		~Jogador();

		void SetGerenciadorDeInput (GerenciadorDeInput *inputs);

		void Machucar (int dano);

		void Mover ();

		void Executar ();
		void Desenhar ();

	private:
		sf::Texture _tex;
		sf::IntRect _tex_rect;
		sf::Sprite _sp;

		GerenciadorDeInput *_inputs;

		int _vida;

		EstadoJogador _estado;
		unsigned _contador;

		sf::Vector2f _posicao;
		sf::Vector2f _old_posicao;

		sf::Vector2f _velocidade;
		sf::Vector2f _old_velocidade;

		sf::Vector2f _aceleracao;
		sf::Vector2f _old_aceleracao;

		bool _no_chao;
};

#endif // JOGADOR_H
