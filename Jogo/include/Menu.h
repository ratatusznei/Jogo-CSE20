#ifndef MENU_H
#define MENU_H

#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

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
