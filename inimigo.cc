#include"inimigo.h"

Inimigo::Inimigo(int x, int y, int w, int h, Vetor<> v, Vetor<> a, Direcao d):
EntidadeDinamica(x,y,w,h,v,a,d){

    flag = -1;
    tipo = EntityType::INIMIGO;

}

Inimigo::Inimigo():
EntidadeDinamica(0,0,0,0, Vetor<> v(0,0), Vetor<> a(0,0),Direcao::left){

    flag = -1;
    tipo = EntityType::INIMIGO;

}

Inimigo::~Inimigo(){}

void Inimigo::atacar(){}

void Inimigo::andar(){}

void Inimigo::executar(){}
