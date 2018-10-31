#include "GerenciadorGrafico.h"

GerenciadorGrafico::GerenciadorGrafico (sf::VideoMode video_mode, string titulo):
_window(video_mode, titulo),
_video_mode(video_mode),
_titulo(titulo)
{
	_window.setVerticalSyncEnabled(true);

	_font_menu.loadFromFile("data/fonts/BLKCHCRY.TTF");
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

void GerenciadorGrafico::Limpa () {
	_window.clear();
}

void GerenciadorGrafico::Atualiza () {
	_window.display();
}

void GerenciadorGrafico::Desenha (Menu menu) {
	sf::Text txt_nome;
        txt_nome.setFont(_font_menu);
	txt_nome.setFillColor(sf::Color::White);
        txt_nome.setString("Jogo");
	txt_nome.setCharacterSize(100);
	txt_nome.setOrigin(txt_nome.getLocalBounds().width / 2, 0);
	txt_nome.setPosition(WINDOW_LENGTH / 2, 0);

	sf::Text txt_jogo_solo;
	txt_jogo_solo.setFont(_font_menu);
	txt_jogo_solo.setFillColor(sf::Color::White);
        txt_jogo_solo.setString("Jogar solo");
	txt_jogo_solo.setCharacterSize(32);
	txt_jogo_solo.setOrigin(txt_jogo_solo.getLocalBounds().width / 2, 0);
	txt_jogo_solo.setPosition(WINDOW_LENGTH / 2, 200);

	sf::Text txt_jogo_coop;
	txt_jogo_coop.setFont(_font_menu);
	txt_jogo_coop.setFillColor(sf::Color::White);
        txt_jogo_coop.setString("Jogar coop");
	txt_jogo_coop.setCharacterSize(32);
	txt_jogo_coop.setOrigin(txt_jogo_coop.getLocalBounds().width / 2, 0);
	txt_jogo_coop.setPosition(WINDOW_LENGTH / 2, 250);

	sf::Text txt_carregar_jogo;
	txt_carregar_jogo.setFont(_font_menu);
	txt_carregar_jogo.setFillColor(sf::Color::White);
        txt_carregar_jogo.setString("Carregar jogo");
	txt_carregar_jogo.setCharacterSize(32);
	txt_carregar_jogo.setOrigin(txt_carregar_jogo.getLocalBounds().width / 2, 0);
	txt_carregar_jogo.setPosition(WINDOW_LENGTH / 2, 300);

	sf::Text txt_creditos;
	txt_creditos.setFont(_font_menu);
	txt_creditos.setFillColor(sf::Color::White);
        txt_creditos.setString("Creditos");
	txt_creditos.setCharacterSize(32);
	txt_creditos.setOrigin(txt_creditos.getLocalBounds().width / 2, 0);
	txt_creditos.setPosition(WINDOW_LENGTH / 2, 350);

	sf::Text txt_sair;
	txt_sair.setFont(_font_menu);
	txt_sair.setFillColor(sf::Color::White);
        txt_sair.setString("Sair");
	txt_sair.setCharacterSize(32);
	txt_sair.setOrigin(txt_sair.getLocalBounds().width / 2, 0);
	txt_sair.setPosition(WINDOW_LENGTH / 2, 430);

	_window.draw(txt_nome);
	_window.draw(txt_jogo_solo);
	_window.draw(txt_jogo_coop);
	_window.draw(txt_carregar_jogo);
	_window.draw(txt_sair);
}

void GerenciadorGrafico::Desenha (Jogo jogo) {

}

void GerenciadorGrafico::Desenha (TelaDeCreditos creditos) {

}

