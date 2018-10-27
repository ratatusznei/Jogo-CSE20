#pragma once

class Entidade{

protected:

    int px;     //Posição em x da entidade
    int py;     //Posição em y da entidade
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
    
    void setx(int x);
    int getx();
    
    void sety(int y);
    int gety();
    
    void setwidth(int w);
    int getwidth();
    
    void setheight(int h);
    int getheight();
    
    void setflag(int f);
    int getflag();
    
    virtual void executar();
    