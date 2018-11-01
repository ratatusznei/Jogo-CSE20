#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico (sf::VideoMode video_mode, string titulo):
_window(video_mode, titulo),
_video_mode(video_mode),
_titulo(titulo)
{
	_window.setVerticalSyncEnabled(true);
}

GerenciadorGrafico::~GerenciadorGrafico () {
	_window.close();
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

void GerenciadorGrafico::Limpa () {
	_window.clear();
}

void GerenciadorGrafico::Atualiza () {
	_window.display();
}

void GerenciadorGrafico::Desenha (Menu& menu) {
	const vector<sf::Text*> opcoes = menu.GetOpcoes();

	for (unsigned i = 0; i < opcoes.size(); i++) {
		_window.draw(*opcoes[i]);
	}
}

void GerenciadorGrafico::Desenha (Jogo& jogo) {

}
