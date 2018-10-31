#include "Principal.h"

Principal::Principal ():
_estado(EnumEstado::Menu),
_janela(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGH), WINDOW_LABEL),
_creditos(),
_menu(_estado),
_jogo()
{
	_creditos.SetCriadores("Pedro", "Fernando");
	_creditos.SetDisciplina("CSE20");
	_creditos.SetProfessor("Simao");
}

Principal::~Principal () {
	//dtor
}

void Principal::Executar () {
	while (_estado != EnumEstado::Sair) {
		sf::Event evento;
		if (_janela.SondarEvento(evento)) {
			if (evento.type == sf::Event::Closed) {
				_estado = EnumEstado::Sair;
			}
		}

		switch (_estado) {
		case EnumEstado::Menu:
			_menu.Executa(_janela.GetPosicaoDoMouse());
			_janela.Desenha(_menu);
			break;

		case EnumEstado::Jogo:
			_jogo.Executa();
			_janela.Desenha(_jogo);
			break;

		case EnumEstado::Tela_de_creditos:
			_creditos.Executa();
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
