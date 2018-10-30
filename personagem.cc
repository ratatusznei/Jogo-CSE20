#include"personagem.h"

Personagem::Personagem(int x, int y, int w, int h, Vetor<> v, Vetor<> a, Direcao d):
EntidadeDinamica(x,y,w,h,v,a,d){

    

}

Personagem::Personagem(int x, int y, int w, int h):
EntidadeDinamica(x,y,w,h,Vetor<> v(0,0), Vetor<> a(0,0),Direcao::right){
    
    
    
}

Personagem::Personagem():
EntidadeDinamica(0,0,0,0,Vetor<> v(0,0), Vetor<> a(0,0),Direcao::right){
 
    
    
}

Personagem::~Personagem(){}

void Personagem::atacar(){}

void Personagem::andar(){}

void Personagem::executar(){}
