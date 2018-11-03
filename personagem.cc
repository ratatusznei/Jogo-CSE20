#include"personagem.h"

Personagem::Personagem
(Vetor<int> p, int w, int h, Vetor<> v, Vetor<> a, Direcao d):
EntidadeDinamica(p,w,h,v,a,d){

    flag = 1;

}

Personagem::Personagem(Vetor<int> p, int w, int h):
EntidadeDinamica(p,w,h,Vetor<> (0,0), Vetor<> (0,0),RIGHT){

    flag = 1;

}

Personagem::Personagem():
EntidadeDinamica(Vetor<int> (0,0),0,0,Vetor<> (0,0), Vetor<> (0,0),RIGHT){

    flag = 1;

}

Personagem::~Personagem(){}

void Personagem::atacar(){}

void Personagem::andar(){}

void Personagem::executar(){}
