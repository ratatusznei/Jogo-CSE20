#include "Principal.h"

Principal::Principal ():
_main(_estado),
_jogo(),
_creditos(_estado),
_estado(EnumEstado::Menu)
{
	GerenciadorGrafico* _janela = GerenciadorGrafico::GetInstance();
	_janela->CriaJanela(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGH), WINDOW_LABEL);
}

Principal::~Principal () {
	//dtor
}

void Principal::Executar () {
	sf::Event evento;
	GerenciadorGrafico* _janela = GerenciadorGrafico::GetInstance();

	bool mouse_clicked = false;

	while (_estado != EnumEstado::Sair) {
		_janela->Limpa();
		mouse_clicked = false;

		if (_janela->SondarEvento(evento)) {
			if (evento.type == sf::Event::Closed) {
				_estado = EnumEstado::Sair;
			}

			else if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Button::Left) {
				mouse_clicked = true;
			}
		}

		switch (_estado) {
		case EnumEstado::Menu:
			_main.Executa(_janela->GetPosicaoDoMouse(), mouse_clicked);
			_main.Desenha();
			break;

		case EnumEstado::Jogo:
			_jogo.Executa();
			_jogo.Desenha();
			break;

		case EnumEstado::Tela_de_creditos:
			_creditos.Executa(_janela->GetPosicaoDoMouse(), mouse_clicked);
			_creditos.Desenha();
			break;

		case EnumEstado::Sair:
			break;

		case EnumEstado::Nenhum:
		default:
			_estado = EnumEstado::Menu;
		}

		_janela->Atualiza();
	}
}
