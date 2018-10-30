#include"personagem.h"

Personagem::Personagem(int x, int y, int w, int h, Vetor<double> v, Vetor<double> a, Direcao d):
EntidadeDinamica(x,y,w,h,v,a,d){

    

}

Personagem::Personagem():
EntidadeDinamica(0,0,0,0,Vetor<double> v(0,0), Vetor<double> a(0,0),EntityType::right){
 
    
    
}

Personagem::~Personagem(){}

void Personagem::atacar(){}

void Personagem::andar(){}

void Personagem::executar(){}
