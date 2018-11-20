#ifndef GERENCIADORDETEXTURAS_H
#define GERENCIADORDETEXTURAS_H

#include <SFML/Graphics.hpp>
#include "common.h"

class GerenciadorDeTexturas {
	public:
		/* 	IN: Nenhum
			OUT: Ponteiro para a instancia unica da classe */
		static GerenciadorDeTexturas* GetInstance ();

		~GerenciadorDeTexturas();

		/*  IN: Nenhum
            OUT: Referencia para a textura correspondente */
		sf::Texture* GetJogador ();
		sf::Texture* GetMumia ();
		sf::Texture* GetPlataforma ();
		sf::Texture* GetPlataformaEgito ();
		sf::Texture* GetCobra ();
		sf::Texture* GetBRobot ();
		sf::Texture* GetAlien ();
		sf::Texture* GetFarao ();

	protected:
		GerenciadorDeTexturas();

		static GerenciadorDeTexturas* _instance;

		static sf::Texture tex_jogador;
		static sf::Texture tex_mumia;
		static sf::Texture tex_plataforma;
		static sf::Texture tex_plataforma_egito;
		static sf::Texture tex_cobra;
		static sf::Texture tex_brobot;
		static sf::Texture tex_alien;
		static sf::Texture tex_farao;
};

#endif // GERENCIADORDETEXTURAS_H
