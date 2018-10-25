#pragma once

class Entidade{

protected:

    int px;     //Posição em x da entidade
    int py;     //Posição em y da entidade
    int width;  //Largura da hitbox da entidade
    int height; //Altura da hitbox da entidade
    
public:

    Entidade();
    ~Entidade();
    
    void setpx(int x);
    int getpx();
    
    void setpy(int y);
    int getpy();
    
    void setwidth(int w);
    int getwidth();
    
    void setheight(int h);
    int getheight();
    
};
