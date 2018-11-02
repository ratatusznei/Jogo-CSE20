#include"inimigo.h"

Inimigo::Inimigo(Vetor<int> p, int w, int h, Vetor<> v, Vetor<> a, Direcao d):
EntidadeDinamica(p,w,h,v,a,d){

    flag = -1;
    tipo = INIMIGO;

}

Inimigo::Inimigo():
EntidadeDinamica(Vetor<int> (0,0),0,0, Vetor<> (0,0), Vetor<> (0,0),LEFT){

    flag = -1;
    tipo = INIMIGO;

}

Inimigo::~Inimigo(){}

void Inimigo::atacar(){}

void Inimigo::andar(){}

void Inimigo::executar(){}
