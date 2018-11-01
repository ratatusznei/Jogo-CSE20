#include"plataforma.h"

Plataforma::Plataforma(Vetor<int> p, int w, int h):
EntidadeEstatica(p,w,h){}

Plataforma::Plataforma():
EntidadeEstatica(Vetor<int>(0,0),0,0){}

Plataforma::~Plataforma(){}

void Plataforma::executar(){}
