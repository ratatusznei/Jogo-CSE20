#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "GerenciadorGrafico.h"
#include "common.h"

using namespace std;

class Menu {
	public:
		Menu (EnumEstado& estado);
		~Menu ();

		void Executa (sf::Vector2i mouse_pos, bool mouse_click);
		void Desenha ();

		void SetFont (string file);
		void IncluiOpcao (string text, int x, int y);

	protected:
		vector<sf::Text*> _opcoes;
		sf::Font _font_menu;
		EnumEstado& _estado;

		virtual void InterpretaClick (int indice) = 0;
};

#endif // MENU_H
