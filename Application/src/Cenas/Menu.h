#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "../common.h"
#include "../GerenciadorGrafico.h"

using namespace std;

class Menu {
	public:
		Menu ();
		~Menu ();

		void Executar (sf::Vector2i mouse_pos, bool mouse_click, EstadoApp *estado);
		void Desenhar ();

		void SetFont (string file);
		void SetFundo (string file);
		void IncluirOpcao (string text, int x, int y);

	protected:
		vector<sf::Text*> _opcoes;

		sf::Font _font;
		sf::Texture _tx_fundo;
		sf::Sprite _sp_fundo;

		virtual EstadoApp InterpretarEscolha (int botao_selecionado) = 0;
};

#endif // MENU_H
