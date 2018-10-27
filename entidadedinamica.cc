#include"entidadedinamica.h"

EntidadeDinamica::EntidadeDinamica(int x, int y, int w, int h, int f):
Entidade(x,y,w,h,f){}

EntidadeDinamica::EntidadeDinamica(){

    px = 0;
    py = 0;
    width = 0;
    height = 0;
    flag = 0;
    
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
    
void EntidadeDinamica::setdirecao(int d){
    direcao = d;
}

int EntidadeDinamica::getdirecao(){
    return direcao;
}

void EntidadeDinamica::executar(){}
