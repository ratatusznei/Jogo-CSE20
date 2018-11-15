#pragma once

#include"../GerenciadorGrafico.h"
#include"linkedlists.h"
#include<fstream>

#include"../Jogador/Jogador.h"
#include"../Inimigos/Inimigo.h"
#include"../Entidades/Plataforma.h"

class Fase{

private:

    Personagem* jogador1;
    Personagem* jogador2;
    Lista<Inimigo*> ListaInimigos;
    Lista<Plataforma*> ListaPlataformas;

public:

    Fase();
    ~Fase();

    void carregaFase(char* path);
    bool isOver();

    void executar();

};
