#include"entidade.h"

Entidade::Entidade(int x, int y, int w, int h, int f){
  
    posicao = (x,y);
    width = w;
    height = h;
    flag = f;
  
}

Entidade::Entidade(){
  
    posicao = (0,0);
    width = 0;
    height = 0;
    flag = 1;

}

Entidade::~Entidade(){}

void Entidade::setpos(int x, int y){
    posicao = (x,y);
}

Vetor<int> Entidade::getpos(){
    return posicao;
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

void Entidade::executar(){}
=======

