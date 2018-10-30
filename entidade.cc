#include"entidade.h"

Entidade::Entidade(int p, int w, int h){
  
    posicao = p;
    width = w;
    height = h;
  
}

Entidade::Entidade(){
  
    posicao = Vetor<int> p(0,0);
    width = 0;
    height = 0;

}

Entidade::~Entidade(){}

void Entidade::setpos(int x, int y){
    posicao = Vetor<int> p(x,y);
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

