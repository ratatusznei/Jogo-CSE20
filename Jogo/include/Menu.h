#ifndef MENU_H
#define MENU_H

#include <SFML/Window/Mouse.hpp>
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

		void Executa (sf::Vector2i mouse_pos);

	private:
		EnumEstado& _estado;
		int _opcao_atual;
		string _opcoes[5];
};

#endif // MENU_H
