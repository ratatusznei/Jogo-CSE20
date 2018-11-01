#pragma once
#include"entidade.h"

class EntidadeEstatica: public Entidade{

protected:



public:

    EntidadeEstatica(Vetor<int> p, int w, int h);
    EntidadeEstatica();
    ~EntidadeEstatica();

    virtual void executar();

};
