#include "Principal.h"

Principal::Principal ():
_estado(EnumEstado::Menu),
_janela(sf::VideoMode(WINDOW_LENGTH, WINDOW_HEIGH), WINDOW_LABEL),
_creditos(),
_menu(_estado),
_jogo()
{
	_menu.SetFont("data/fonts/BLKCHCRY.TTF");
	_menu.IncluiOpcao("Jogar solo", WINDOW_LENGTH / 2, 200);
	_menu.IncluiOpcao("Jogar co-op", WINDOW_LENGTH / 2, 250);
	_menu.IncluiOpcao("Carregar jogo", WINDOW_LENGTH / 2, 300);
	_menu.IncluiOpcao("Creditos", WINDOW_LENGTH / 2, 350);
	_menu.IncluiOpcao("Sair", WINDOW_LENGTH / 2, 430);

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
			_menu.Executa(_janela.GetPosicaoDoMouse(), _janela.GetMouseClick());
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
