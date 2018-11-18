#include "GerenciadorDeTexturas.h"

GerenciadorDeTexturas* GerenciadorDeTexturas::_instance = NULL;

sf::Texture GerenciadorDeTexturas::tex_jogador;
sf::Texture GerenciadorDeTexturas::tex_mumia;
sf::Texture GerenciadorDeTexturas::tex_plataforma;
sf::Texture GerenciadorDeTexturas::tex_plataforma_egito;
sf::Texture GerenciadorDeTexturas::tex_cobra;
sf::Texture GerenciadorDeTexturas::tex_brobot;
sf::Texture GerenciadorDeTexturas::tex_alien;

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
	tex_plataforma_egito.loadFromFile(Resources::tex_plataforma_egito);
	tex_cobra.loadFromFile(Resources::tex_cobra);
	tex_brobot.loadFromFile(Resources::tex_brobot);
	tex_alien.loadFromFile(Resources::tex_alien);
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

sf::Texture* GerenciadorDeTexturas::GetPlataformaEgito () {
	return &tex_plataforma_egito;
}

sf::Texture* GerenciadorDeTexturas::GetCobra () {
	return &tex_cobra;
}

sf::Texture* GerenciadorDeTexturas::GetBRobot () {
	return &tex_brobot;
}

sf::Texture* GerenciadorDeTexturas::GetAlien () {
	return &tex_alien;
}
