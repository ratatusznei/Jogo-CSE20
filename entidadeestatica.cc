#include"entidadeestatica.h"

EntidadeEstatica::EntidadeEstatica(int x, int y, int w, int h, int f):
Entidade(x,y,w,h,f){}

EntidadeEstatica::EntidadeEstatica():
Entidade(0,0,0,0,0){}

EntidadeEstatica::~EntidadeEstatica(){}

void EntidadeEstatica::executar(){}
