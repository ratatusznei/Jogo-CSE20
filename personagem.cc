#include"personagem.h"

Personagem::Personagem(int x, int y, int w, int h):
EntidadeDinamica(x,y,w,h,1){}

Personagem::Personagem():
EntidadeDinamica(0,0,0,0,1){}

Personagem::~Personagem(){}

void Personagem::atacar(){}

void Personagem::andar(){}

void Personagem::executar(){}
