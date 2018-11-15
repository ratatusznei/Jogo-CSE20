#pragma once

#include"../Principal.h"

#include<SFML/System.hpp>

#include"../GerenciadorGrafico.h"
#include"../GerenciadorDeColisao.h"
#include"linkedlists.h"
#include<fstream>

#include"../Jogador/Jogador.h"
#include"../Inimigos/Inimigo.h"
#include"../Entidades/Plataforma.h"

class Fase{

private:

    int isOver;
    Personagem* jogador1;
    Personagem* jogador2;
    Lista<Inimigo*> ListaInimigos;
    Lista<Plataforma*> ListaPlataformas;

public:

    Fase();
    ~Fase();

    void carregaFase(char* path);

    void executar();

};
