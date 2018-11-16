/*
	Representacao de um menu

	Cria botoes e checa clickes neles
*/

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

		/*	IN: Estado do mouse e referencia para o estado global da aplicacao
			OUT: Altera o estado do app conforme o botao clicado */
		void Executar (sf::Vector2i mouse_pos, bool mouse_click, EstadoApp *estado);

		/*	IN: Nenhum
			OUT: Desenha o menu na janela */
		void Desenhar ();

		/*	IN: Arquivo da fonte
			OUT: Os botoes do menu usarao essa fonte */
		void SetFont (string file);

		/*	IN: Arquivo do fundo
			OUT: O menu vai usar esse fundo */
		void SetFundo (string file);

		/*	IN: Texto e posicao do novo botao
			OUT: Inclui uma nova opcao no menu, que eh representada por um botao */
		void IncluirOpcao (string text, int x, int y);

	protected:
		vector<sf::Text*> _opcoes;

		sf::Font _font;
		sf::Texture _tx_fundo;
		sf::Sprite _sp_fundo;

		/*	IN: Indice do botao selecionado
			OUT: Retorna o novo estado que o botao selecionado representa */
		virtual EstadoApp InterpretarEscolha (int botao_selecionado) = 0;
};

#endif // MENU_H
