#include"inimigo.h"

Inimigo::Inimigo(int x, int y, int w, int h):
EntidadeDinamica(x,y,w,h,-1){}

Inimigo::Inimigo():
EntidadeDinamica(0,0,0,0,-1){}

Inimigo::~Inimigo(){}

void Inimigo::atacar(){}

void Inimigo::andar(){}

void Inimigo::executar(){}
