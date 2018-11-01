#ifndef MENU_H
#define MENU_H

#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

#define NUM_OPCOES 5

using namespace std;

class GerenciadorGrafico;

enum class EnumEstado {
	Nenhum = 0,
	Menu,
	Jogo,
	Tela_de_creditos,
	Sair,
};

class Menu {
	public:
		Menu (EnumEstado& estado);
		~Menu ();

		void Executa (sf::Vector2i mouse_pos, bool mouse_click);

		void SetFont (string file);
		void IncluiOpcao (string text, int x, int y);
		const vector<sf::Text*>& GetOpcoes ();

	private:
		vector<sf::Text*> _opcoes;
		sf::Font _font_menu;
		EnumEstado& _estado;
};

#endif // MENU_H
