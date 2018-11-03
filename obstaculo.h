#pragma once

#include"entidadeestatica.h"

class Obstaculo: public EntidadeEstatica{

protected:



public:

    Obstaculo(Vetor<int> p, int w, int h, int f);
    Obstaculo();
    ~Obstaculo();

    virtual void executar();

};
