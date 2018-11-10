#ifndef GERENCIADORDEINPUT_H
#define GERENCIADORDEINPUT_H

#include <SFML/Window/Keyboard.hpp>
#include "../common.h"

class GerenciadorDeInput {
	public:
		GerenciadorDeInput ();
		~GerenciadorDeInput ();

		bool GetDireita ();
		bool GetEsquerda ();
		bool GetPulo ();
		bool GetAtaque ();

	private:
};

#endif // GERENCIADORDEINPUT_H
