#include "Menu.h"

Menu::Menu (EnumEstado& estado):
_estado(estado),
_opcao_atual(-1)
{
	_opcoes[0] = "Jogo solo";
	_opcoes[1] = "Jogo co-op";
	_opcoes[2] = "Carregar jogo";
	_opcoes[3] = "Creditos";
	_opcoes[4] = "Sair";
}

Menu::~Menu () {
	//dtor
}

void Menu::Executa (sf::Vector2i mouse_pos) {

}
