#ifndef FASE_H
#define FASE_H

#include<SFML/System.hpp>
#include<fstream>

#include "../GerenciadorGrafico.h"
#include "../GerenciadorDeColisao.h"
#include "../LinkedLists.h"

#include "../Jogador/Jogador.h"
#include "../Inimigos/Inimigo.h"
#include "../Entidades/Plataforma.h"

class Fase {

private:
	int _isOver;

	Personagem* _jogador1;
	Personagem* _jogador2;

	Lista<Inimigo*> _listaInimigos;
	Lista<Plataforma*> _listaPlataformas;

public:
	Fase ();
	~Fase ();

	void CarregarFase (char* path);

	void Executar ();
};


#endif // FASE_H
