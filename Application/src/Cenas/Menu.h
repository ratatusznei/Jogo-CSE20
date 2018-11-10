#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "../common.h"
#include "GerenciadorGrafico.h"

using namespace std;

class Menu {
	public:
		Menu (EnumEstado& estado);
		~Menu ();

		void Executa (sf::Vector2i mouse_pos, bool mouse_click);
		void Desenha ();

		void SetFont (string file);
		void SetFundo (string file);
		void IncluiOpcao (string text, int x, int y);

	protected:
		vector<sf::Text*> _opcoes;
		EnumEstado& _estado;

		sf::Font _font;
		sf::Texture _tx_fundo;
		sf::Sprite _sp_fundo;

		virtual void InterpretaClick (int indice) = 0;
};

#endif // MENU_H
