#include "Principal.h"

Principal::Principal ():
_main(),
_jogo(),
_creditos(),
_estado(EstadoApp::Menu)
{
	GerenciadorGrafico* _janela = GerenciadorGrafico::GetInstance();
	_janela->CriaJanela(sf::VideoMode(Janela::largura, Janela::altura), Janela::titulo);
}

Principal::~Principal () {
	//dtor
}

void Principal::Executar () {
	sf::Event evento;
	GerenciadorGrafico* _janela = GerenciadorGrafico::GetInstance();

	bool mouse_clicked = false;

	while (_estado != EstadoApp::Sair) {
		_janela->Limpar();
		mouse_clicked = false;

		if (_janela->SondarEvento(evento)) {
			if (evento.type == sf::Event::Closed) {
				_estado = EstadoApp::Sair;
			}

			else if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Button::Left) {
				mouse_clicked = true;
			}

			else if (_estado == EstadoApp::Jogo && evento.type == sf::Event::KeyPressed && evento.key.code == sf::Keyboard::P) {
                _jogo.TogglePausa();
			}
		}

		switch (_estado) {
		case EstadoApp::Menu:
			_main.Executar(_janela->GetPosicaoDoMouse(), mouse_clicked, &_estado);
			_main.Desenhar();
			break;

		case EstadoApp::Iniciar_jogo_coop:
			_jogo.Iniciar(true);
			_estado = EstadoApp::Jogo;
			break;

		case EstadoApp::Iniciar_jogo_solo:
			_jogo.Iniciar(false);
			_estado = EstadoApp::Jogo;
			break;

		case EstadoApp::Jogo:
			_jogo.Executar();
			_jogo.Desenhar();

			if (_jogo.GameOver()) {
				_estado = EstadoApp::Menu;
				GerenciadorGrafico::GetInstance()->ResetCamera();
			}
			break;

		case EstadoApp::Tela_de_creditos:
			_creditos.Executar(_janela->GetPosicaoDoMouse(), mouse_clicked, &_estado);
			_creditos.Desenhar();
			break;

		case EstadoApp::Sair:
			break;

		case EstadoApp::Nenhum:
		default:
			_estado = EstadoApp::Menu;
		}

		_janela->Atualizar();
	}
}
