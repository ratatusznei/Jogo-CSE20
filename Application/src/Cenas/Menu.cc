#include "Menu.h"

Menu::Menu ():
_opcoes(),
_txFundo(),
_spFundo()
{
}

Menu::~Menu () {
	for (unsigned i = 0; i < _opcoes.size(); i++) {
		delete _opcoes[i];
	}
}

void Menu::Executar (sf::Vector2i mouse_pos, bool mouse_click, EstadoApp *estado) {
	for (unsigned i = 0; i < _opcoes.size(); i++) {
		sf::FloatRect txt_box = _opcoes[i]->getGlobalBounds();

		if (txt_box.contains(mouse_pos.x, mouse_pos.y)) {
			_opcoes[i]->setFillColor(sf::Color::Green);

			if (mouse_click) {
				_opcoes[i]->setFillColor(sf::Color::Red);
				*estado = InterpretarEscolha(i);
			}
		}
		else {
			_opcoes[i]->setFillColor(sf::Color::Black);
		}
	}
}

void Menu::Desenhar () {
	GerenciadorGrafico* janela = GerenciadorGrafico::GetInstance();

	janela->Desenhar(_spFundo);

	for (unsigned i = 0; i < _opcoes.size(); i++) {
		janela->Desenhar(*_opcoes[i]);
	}
}

void Menu::SetFont (string file) {
	_font.loadFromFile(file);
}

void Menu::SetFundo (string file) {
	_txFundo.loadFromFile(file);
	_spFundo.setTexture(_txFundo);
}

void Menu::IncluirOpcao (string text, int x, int y) {
	sf::Text* nova_opcao = new sf::Text(text, _font, 32);
	nova_opcao->setFillColor(sf::Color::Black);
	nova_opcao->setPosition(x - nova_opcao->getLocalBounds().width / 2, y);

	_opcoes.push_back(nova_opcao);
}
