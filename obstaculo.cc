#include"obstaculo.h"

Obstaculo::Obstaculo(Vetor<int> p, int w, int h, int f):
EntidadeEstatica(p,w,h){

    flag = f;

}

Obstaculo::Obstaculo():
EntidadeEstatica(Vetor<int> (0,0), 0, 0){

    flag = 0;

}

Obstaculo::~Obstaculo(){}

void Obstaculo::executar(){}
