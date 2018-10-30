#include"inimigo.h"

Inimigo::Inimigo(int x, int y, int w, int h):
EntidadeDinamica(x,y,w,h){

    flag = -1;
    tipo = EntityType::INIMIGO;

}

Inimigo::Inimigo():
EntidadeDinamica(0,0,0,0){

    flag = -1;
    tipo = EntityType::INIMIGO;

}

Inimigo::~Inimigo(){}

void Inimigo::atacar(){}

void Inimigo::andar(){}

void Inimigo::executar(){}
