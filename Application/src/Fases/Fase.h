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
	bool Executar (Jogador* j1, Jogador* j2, Lista<Inimigo*>* li,
                    Lista<Plataforma*>* lp, GerenciadorDeColisao* colisoes);

private:

	bool _isOver;
    GerenciadorGrafico *janela;

};


#endif // FASE_H
