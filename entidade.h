#pragma once

#include"vetor.h"

class Entidade{

protected:

    Vetor posicao<int>  //Vetor posição da entidade
    int width;  //Largura da hitbox da entidade
    int height; //Altura da hitbox da entidade
    int flag;   /*
                  Determina internamente como a entidade vai se comportar 
                  no que diz respeito ao tratamento de colisão
                  Flag negativa = inimigo
                  Flag positiva = amigo
                */
    
public:

    Entidade(int x, int y, int w, int h, int f);
    Entidade();
    ~Entidade();
    
    void setpos(int x, int y);
    Vetor<int> getpos();
    
    void setwidth(int w);
    int getwidth();
    
    void setheight(int h);
    int getheight();
    
    void setflag(int f);
    int getflag();
    
    virtual void executar();
    
