#include"plataforma.h"

Plataforma::Plataforma(int x, int y, int w, int h):
EntidadeEstatica(x,y,w,h,0){}

Plataforma::Plataforma():
EntidadeEstatica(0,0,0,0,0){}

Plataforma::~Plataforma(){}

void Plataforma::executar(){}
