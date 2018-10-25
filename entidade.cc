#include"entidade.h"

Entidade::Entidade(int x, int y, int w, int h, int f){
  
    px = x;
    py = y;
    width = w;
    height = h;
    flag = f;
  
}

Entidade::Entidade(){
  
    px = 0;
    py = 0;
    width = 0;
    height = 0;
    flag = 1;

}

Entidade::~Entidade(){}

void Entidade::setx(int x){
    px = x;
}

int Entidade::getx(){
    return px;
}

void Entidade::sety(int y){
    py = y;
}

int Entidade::gety(){
    return py;
}

void Entidade::setwidth(int w){
    width = w;
}

int Entidade::getwidth(){
    return width;
}

void Entidade::setheight(int h){
    height = h;
}

int Entidade::getheight(){
    return height;
}

void Entidade::setflag(int f){
    flag = f;
}

int Entidade::getflag(){
    return flag;
}
