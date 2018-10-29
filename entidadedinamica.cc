#include"entidadedinamica.h"

EntidadeDinamica::EntidadeDinamica
(int x, int y, int w, int h, int f, Vetor<double> v, Vetor<double> a, Direcao d):
Entidade(x,y,w,h,f){

    velocidade = v;
    aceleracao = a;
    dir = d;

}

EntidadeDinamica::EntidadeDinamica():
Entidade(0,0,0,0,-1){

    velocidade = Vetor<double>(0,0);
    aceleracao = Vetor<double>(0,0);
    dir = Direcao::left;
    
}

EntidadeDinamica::~EntidadeDinamica(){}

void EntidadeDinamica::setvel(Vetor<double> v){
    velocidade = v;
}

void EntidadeDinamica::setvel(double vx, double vy){
    velocidade = (vx, vy);
}

Vetor<double> EntidadeDinamica::getvel(){
    return velocidade;
}
   
void EntidadeDinamica::setace(Vetor<double> a){
    aceleracao = a;
}

void EntidadeDinamica::setace(double ax, double ay){
    aceleracao = (ax, ay);
}

Vetor<double> EntidadeDinamica::getace(){
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
