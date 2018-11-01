#include "Principal.h"

Principal::Principal ():
_janela(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGH), WINDOW_LABEL),
_main(_estado),
_jogo(),
_creditos(_estado),
_estado(EnumEstado::Menu)
{
}

Principal::~Principal () {
	//dtor
}

void Principal::Executar () {
	sf::Event evento;
	bool mouse_clicked = false;

	while (_estado != EnumEstado::Sair) {
		_janela.Limpa();
		mouse_clicked = false;

		if (_janela.SondarEvento(evento)) {
			if (evento.type == sf::Event::Closed) {
				_estado = EnumEstado::Sair;
			}

			else if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Button::Left) {
				mouse_clicked = true;
			}
		}

		switch (_estado) {
		case EnumEstado::Menu:
			_main.Executa(_janela.GetPosicaoDoMouse(), mouse_clicked);
			_janela.Desenha(_main);
			break;

		case EnumEstado::Jogo:
			_jogo.Executa();
			_janela.Desenha(_jogo);
			break;

		case EnumEstado::Tela_de_creditos:
			_creditos.Executa(_janela.GetPosicaoDoMouse(), mouse_clicked);
			_janela.Desenha(_creditos);
			break;

		case EnumEstado::Sair:
			break;

		case EnumEstado::Nenhum:
		default:
			_estado = EnumEstado::Menu;
		}

		_janela.Atualiza();
	}
}
