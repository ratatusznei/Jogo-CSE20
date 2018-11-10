#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::_instance = NULL;

GerenciadorGrafico* GerenciadorGrafico::GetInstance () {
	if (_instance == NULL) {
		_instance = new GerenciadorGrafico();
	}

	return _instance;
}

GerenciadorGrafico::GerenciadorGrafico ():
_window(),
_video_mode(),
_titulo()
{

}

GerenciadorGrafico::~GerenciadorGrafico () {
	_window.close();
}

void GerenciadorGrafico::CriaJanela (sf::VideoMode video_mode, string titulo) {
	_video_mode = video_mode;
	_titulo = titulo;

	_window.create(video_mode, titulo, sf::Style::Close);
	_window.setVerticalSyncEnabled(true);
}

bool GerenciadorGrafico::EstaAberta () {
	return _window.isOpen();
}

bool GerenciadorGrafico::SondarEvento (sf::Event& evento) {
	return _window.pollEvent(evento);
}

sf::Vector2i GerenciadorGrafico::GetPosicaoDoMouse () {
	return sf::Mouse::getPosition(_window);
}

bool GerenciadorGrafico::GetMouseClick() {
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void GerenciadorGrafico::Limpar () {
	_window.clear();
}

void GerenciadorGrafico::Atualizar () {
	_window.display();
}

void GerenciadorGrafico::Desenhar (sf::Drawable& objeto) {
	_window.draw(objeto);
}
