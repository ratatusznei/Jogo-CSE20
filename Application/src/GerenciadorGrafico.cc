#include "GerenciadorGrafico.h"

GerenciadorGrafico* GerenciadorGrafico::_instance = NULL;

GerenciadorGrafico* GerenciadorGrafico::GetInstance () {
	if (_instance == NULL) {
		_instance = new GerenciadorGrafico();
	}

	return _instance;
}

GerenciadorGrafico::GerenciadorGrafico ():
_timer(),
_deltaT(0),
_camera(),
_window(),
_videoMode(),
_titulo()
{

}

GerenciadorGrafico::~GerenciadorGrafico () {
	_window.close();
}

void GerenciadorGrafico::CriaJanela (sf::VideoMode video_mode, string titulo) {
	_videoMode = video_mode;
	_titulo = titulo;

	sf::FloatRect camera_rect(0, 0, video_mode.width, video_mode.height);
	_camera.reset(camera_rect);


	_window.create(video_mode, titulo, sf::Style::Close);
	_window.setVerticalSyncEnabled(true);
	_window.setView(_camera);
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

float GerenciadorGrafico::GetDeltaTime () {
	return _deltaT;
}

void GerenciadorGrafico::SetCamera (int x) {
	_camera.setCenter(x, _videoMode.height / 2);
	_window.setView(_camera);
}

void GerenciadorGrafico::ResetCamera () {
	sf::FloatRect camera_rect(0, 0, _videoMode.width, _videoMode.height);
	_camera.reset(camera_rect);
	_window.setView(_camera);
}

void GerenciadorGrafico::Limpar () {
	_window.clear();
}

void GerenciadorGrafico::Atualizar () {
	_window.display();
	_deltaT = _timer.restart().asSeconds();
}

void GerenciadorGrafico::Desenhar (sf::Drawable& objeto) {
	_window.draw(objeto);
}
