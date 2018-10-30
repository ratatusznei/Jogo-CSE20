#include"entidadedinamica.h"

EntidadeDinamica::EntidadeDinamica
(Vetor<int> p, int w, int h, Vetor<> v, Vetor<> a, Direcao d):
Entidade(p,w,h){

    velocidade = v;
    aceleracao = a;
    dir = d;

}

EntidadeDinamica::EntidadeDinamica():
Entidade(Vetor<int> p(0,0),0,0){

    velocidade = Vetor<> v(0,0);
    aceleracao = Vetor<> a(0,0);
    dir = Direcao::left;
    
}

EntidadeDinamica::~EntidadeDinamica(){}

void EntidadeDinamica::setvel(Vetor<> v){
    velocidade = v;
}

void EntidadeDinamica::setvel(double vx, double vy){
    velocidade = Vetor<> v(vx, vy);
}

Vetor<> EntidadeDinamica::getvel(){
    return velocidade;
}
   
void EntidadeDinamica::setace(Vetor<> a){
    aceleracao = a;
}

void EntidadeDinamica::setace(double ax, double ay){
    aceleracao = Vetor<> a(ax, ay);
}

Vetor<> EntidadeDinamica::getace(){
    return aceleracao;
}
    
void EntidadeDinamica::setdirecao(){
    
    if(dir == Direcao::left)
        dir = Direcao::right;
    else
        dir = Direcao::left;
    
}

void EntidadeDinamica::andar(){}

void EntidadeDinamica::atacar(){}

void EntidadeDinamica::executar(){}
