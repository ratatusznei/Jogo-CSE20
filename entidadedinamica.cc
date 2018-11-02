#include"entidadedinamica.h"

EntidadeDinamica::EntidadeDinamica
(Vetor<int> p, int w, int h, Vetor<> v, Vetor<> a, Direcao d):
Entidade(p,w,h){

    velocidade = v;
    aceleracao = a;
    dir = d;

}

EntidadeDinamica::EntidadeDinamica():
Entidade(Vetor<int> (0,0),0,0){

    velocidade(0,0);
    aceleracao(0,0);
    dir = LEFT;

}

EntidadeDinamica::~EntidadeDinamica(){}

void EntidadeDinamica::setvel(Vetor<>& v){
    velocidade = v;
}

void EntidadeDinamica::setvel(double vx, double vy){
    velocidade(vx, vy);
}

Vetor<> EntidadeDinamica::getvel(){
    return velocidade;
}

void EntidadeDinamica::setace(Vetor<>& a){
    aceleracao = a;
}

void EntidadeDinamica::setace(double ax, double ay){
    aceleracao(ax, ay);
}

Vetor<> EntidadeDinamica::getace(){
    return aceleracao;
}

void EntidadeDinamica::setdirecao(){

    if(dir == LEFT)
        dir = RIGHT;
    else
        dir = LEFT;

}

void EntidadeDinamica::andar(){}

void EntidadeDinamica::atacar(){}

void EntidadeDinamica::executar(){}
