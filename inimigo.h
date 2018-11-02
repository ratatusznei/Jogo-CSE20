#pragma once

#include"entidadedinamica.h"

class Inimigo: public EntidadeDinamica{

protected:



public:

    Inimigo(Vetor<int> p, int w, int h, Vetor<> v, Vetor<> a, Direcao d);
    Inimigo();
    ~Inimigo();

    virtual void atacar();
    virtual void andar();
    virtual void executar();

};
