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

	/*	IN: Path para um arquivo de fase
		OUT: Preenche as listas de entidades conforme o arquivo */
	void CarregarFase (char* path);

	/*	IN: Nenhum
		OUT: Executa os objetos internos */
	void Executar ();

private:
	int _isOver;

	Personagem* _jogador1;
	Personagem* _jogador2;

	Lista<Inimigo*> _listaInimigos;
	Lista<Plataforma*> _listaPlataformas;
};


#endif // FASE_H
