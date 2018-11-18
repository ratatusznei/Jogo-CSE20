/*
	Classe que representa fases

	Possui os inimigos e plataformas da fase
	Possui referencias para os jogadores
*/


#ifndef FASE_H
#define FASE_H

#include <SFML/System.hpp>
#include <fstream>

#include "../GerenciadorGrafico.h"
#include "../GerenciadorDeColisao.h"
#include "../LinkedLists.h"

#include "../Jogador/Jogador.h"
#include "../Inimigos/Inimigo.h"
#include "../Entidades/Plataforma.h"

class Fase {
	public:
		Fase ();
		~Fase ();

		/*	IN: Nenhum
			OUT: Executa os objetos internos */
		bool Executar ();

	private:
		Jogador* _jogador1;
		Jogador* _jogador2;

		Lista<Inimigo*> _listaInimigos;
		Lista<Plataforma*> _listaPlataformas;

		bool _isOver;
};


#endif // FASE_H
