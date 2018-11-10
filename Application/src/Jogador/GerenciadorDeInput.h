#ifndef GERENCIADORDEINPUT_H
#define GERENCIADORDEINPUT_H

#include <SFML/Window/Keyboard.hpp>
#include "../common.h"

class GerenciadorDeInput {
	public:
		GerenciadorDeInput ();
		~GerenciadorDeInput ();

		void SetKeyEsquerda (sf::Keyboard::Key key);
		void SetKeyDireita (sf::Keyboard::Key key);
		void SetKeyPulo (sf::Keyboard::Key key);
		void SetKeyAtaque (sf::Keyboard::Key key);

		void Atualizar ();

		bool GetEsquerda ();
		bool GetDireita ();
		bool GetPulo ();
		bool GetAtaque ();

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
