#include"entidadeestatica.h"

EntidadeEstatica::EntidadeEstatica(Vetor<int> p, int w, int h):
Entidade(p,w,h){}

EntidadeEstatica::EntidadeEstatica():
Entidade(Vetor<int> (0,0),0,0){}

EntidadeEstatica::~EntidadeEstatica(){}

void EntidadeEstatica::executar(){}
