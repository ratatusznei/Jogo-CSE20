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

		sf::Texture* GetJogador ();
		sf::Texture* GetMumia ();
		sf::Texture* GetPlataforma ();

	protected:
		GerenciadorDeTexturas();

		static GerenciadorDeTexturas* _instance;

		static sf::Texture tex_jogador;
		static sf::Texture tex_mumia;
		static sf::Texture tex_plataforma;

	private:
};

#endif // GERENCIADORDETEXTURAS_H
