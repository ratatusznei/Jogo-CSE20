#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "common.h"

using namespace std;

class Menu {
	public:
		Menu (EnumEstado& estado);
		virtual ~Menu ();

		void Executa (sf::Vector2i mouse_pos, bool mouse_click);

		void SetFont (string file);
		void IncluiOpcao (string text, int x, int y);
		const vector<sf::Text*>& GetOpcoes ();

	protected:
		vector<sf::Text*> _opcoes;
		sf::Font _font_menu;
		EnumEstado& _estado;

		virtual void InterpretaClick (int indice) = 0;
};

#endif // MENU_H
