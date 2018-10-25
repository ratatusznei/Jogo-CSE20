#pragma once

class Entidade{

protected:

    int px;     //Posição em x da entidade
    int py;     //Posição em y da entidade
    int width;  //Largura da hitbox da entidade
    int height; //Altura da hitbox da entidade
    int flag;   /*Determina internamente como a entidade vai se comportar
                  Flag negativa = inimigo
                  Flag positiva = amigo
                  Flag zero = plataforma ou obstáculo
                  Basicamente é uma maneira da entidade saber o que ela é
                */
    
public:

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
    
};
