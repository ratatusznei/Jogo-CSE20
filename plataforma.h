#pragma once
#include"entidadeestatica.h"

class Plataforma: public EntidadeEstatica{

protected:



public:

    Plataforma(Vetor<int> p, int w, int h);
    Plataforma();
    ~Plataforma();

    virtual void executar();

};
