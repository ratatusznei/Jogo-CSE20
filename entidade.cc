#include"entidade.h"

Entidade::Entidade(){
  
    px = 0;
    py = 0;
    width = 0;
    height = 0;

}

Entidade::~Entidade(){}

void Entidade::setpx(int px){
    px = x;
}

int Entidade::getpx(){
    return px;
}

