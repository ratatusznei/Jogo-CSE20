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

void EntidadeDinamica::executar(){}
