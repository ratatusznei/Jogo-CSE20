#ifndef JOGADOR_H
#define JOGADOR_H

#include "../Cenas/GerenciadorGrafico.h"

class Jogador {
	public:
		Jogador();
		~Jogador();

		void Andar ();
		void Executa ();
		void Desenha ();

	private:
		sf::Vector2f _posicao;
		sf::Vector2f _old_posicao;

		sf::Vector2f _velocidade;
		sf::Vector2f _old_velocidade;

		sf::Vector2f _aceleracao;
		sf::Vector2f _old_aceleracao;
};

#endif // JOGADOR_H
