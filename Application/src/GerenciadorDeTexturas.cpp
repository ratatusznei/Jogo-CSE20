#include "GerenciadorDeTexturas.h"

GerenciadorDeTexturas* GerenciadorDeTexturas::_instance = NULL;

sf::Texture GerenciadorDeTexturas::tex_jogador;
sf::Texture GerenciadorDeTexturas::tex_mumia;
sf::Texture GerenciadorDeTexturas::tex_plataforma;

GerenciadorDeTexturas* GerenciadorDeTexturas::GetInstance () {
	if (_instance == NULL) {
		_instance = new GerenciadorDeTexturas();
	}

	return _instance;
}

GerenciadorDeTexturas::GerenciadorDeTexturas () {
	tex_jogador.loadFromFile(Resources::tex_jogador);
	tex_mumia.loadFromFile(Resources::tex_mumia);
	tex_plataforma.loadFromFile(Resources::tex_plataforma);
}

GerenciadorDeTexturas::~GerenciadorDeTexturas () {
	//dtor
}

sf::Texture* GerenciadorDeTexturas::GetJogador () {
	return &tex_jogador;
}

sf::Texture* GerenciadorDeTexturas::GetMumia () {
	return &tex_mumia;
}

sf::Texture* GerenciadorDeTexturas::GetPlataforma () {
	return &tex_plataforma;
}
