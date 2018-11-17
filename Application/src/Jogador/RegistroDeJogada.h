#ifndef REGISTRODEJOGADA_H
#define REGISTRODEJOGADA_H

#include "Jogador.h"
#include "../Inimigos/Inimigo.h"
#include "../Entidades/Plataforma.h"
#include "../LinkedLists.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <string.h>

class RegistroDeJogada{

public:

    RegistroDeJogada(const char* nome);
    ~RegistroDeJogada();

    void salvarJogada(Jogador* j1, Jogador* j2,
                      Lista<Inimigo*>* li, Lista<Plataforma*>* lp,
                      int* pontuacao, const char* fase);
    void carregarJogada(Jogador* j1, Jogador* j2,
                        Lista<Inimigo*>* li, Lista<Plataforma*>* lp,
                        int* pontuacao);

private:

    const char* _nome_jogada;
    char* _path;

};

#endif // REGISTRODEJOGADA_H
