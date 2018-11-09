#include "Menu.h"

Menu::Menu (EnumEstado& estado):
_opcoes(),
_font_menu(),
_estado(estado)
{
	_font_menu.loadFromFile("data/fonts/BLKCHCRY.TTF");
}

Menu::~Menu () {
	for (unsigned i = 0; i < _opcoes.size(); i++) {
		delete _opcoes[i];
	}
}

void Menu::Executa (sf::Vector2i mouse_pos, bool mouse_click) {
	for (unsigned i = 0; i < _opcoes.size(); i++) {
		sf::FloatRect txt_box = _opcoes[i]->getGlobalBounds();

		if (txt_box.contains(mouse_pos.x, mouse_pos.y)) {
			_opcoes[i]->setFillColor(sf::Color::Green);

			if (mouse_click) {
				_opcoes[i]->setFillColor(sf::Color::Red);
				InterpretaClick(i);
			}
		}
		else {
			_opcoes[i]->setFillColor(sf::Color::White);
		}
	}
}

void Menu::Desenha () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();

	for (unsigned i = 0; i < _opcoes.size(); i++) {
		janela->Desenha(*_opcoes[i]);
	}
}

void Menu::SetFont (string file) {
	_font_menu.loadFromFile(file);
}

void Menu::IncluiOpcao (string text, int x, int y) {
	sf::Text* nova_opcao = new sf::Text(text, _font_menu, 32);
	nova_opcao->setFillColor(sf::Color::White);
	nova_opcao->setPosition(x - nova_opcao->getLocalBounds().width / 2, y);

	_opcoes.push_back(nova_opcao);
}
