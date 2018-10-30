#pragma once

#include"entidadedinamica.h"

class Inimigo{

protected:



public:

    Inimigo(Vetor<int> p, int w, int h, Vetor<> v, Vetor<> a, Direcao d);
    Inimigo();
    ~Inimigo();
    
    virtual void atacar();
    virtual void andar();
    virtual void executar();

};
