/*
	Interface das entradas do usuario para o controle do personagem

	TODO: Implementar isso atraves de um bridge se der tempo
*/

#ifndef GERENCIADORDEINPUT_H
#define GERENCIADORDEINPUT_H

#include <SFML/Window/Keyboard.hpp>
#include "../common.h"

class GerenciadorDeInput {
	public:
		GerenciadorDeInput ();
		~GerenciadorDeInput ();

		/*	IN: Entrada do teclado
			OUT: Configura essa tecla para os Gets a seguir */
		void SetKeyEsquerda (sf::Keyboard::Key key);
		void SetKeyDireita (sf::Keyboard::Key key);
		void SetKeyPulo (sf::Keyboard::Key key);
		void SetKeyAtaque (sf::Keyboard::Key key);

		/*	IN: Nenhum
			OUT: Atualiza os boleanos internos */
		void Atualizar ();

		/*	IN: Nenhum
			OUT: Retorna verdadeiro ou falso conforme as teclas configuradas */
		bool GetEsquerda (); // Retorna true em nivel
		bool GetDireita (); // Retorna true em nivel
		bool GetPulou (); // Retorna true em borda
		bool GetPulando ();  // Retorna true em nivel
		bool GetAtacou (); // Retorna true em borda

	private:
		bool _esquerda;
		bool _direita;
		bool _pulo;
		bool _old_pulo;
		bool _ataque;
		bool _old_ataque;

		sf::Keyboard::Key _key_esquerda;
		sf::Keyboard::Key _key_direita;
		sf::Keyboard::Key _key_pulo;
		sf::Keyboard::Key _key_ataque;
};

#endif // GERENCIADORDEINPUT_H
