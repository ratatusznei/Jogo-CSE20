#include"personagem.h"

Personagem::Personagem(int x, int y, int w, int h):
Entidade(x,y,w,h,1){}

Personagem::Personagem(){

    px = 0;
    py = 0;
    width = 0;
    height = 0;
    flag = 1;
    
}

Personagem::~Personagem(){}

void Personagem::executar(){}
