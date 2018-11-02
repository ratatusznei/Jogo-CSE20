#pragma once

#include"entidadedinamica.h"

class Personagem: public EntidadeDinamica{

protected:



public:

    Personagem(Vetor<int> p, int w, int h, Vetor<> v, Vetor<> a, Direcao d);
    Personagem(Vetor<int> p, int w, int h);
    Personagem();
    ~Personagem();

    virtual void andar();
    virtual void atacar();
    virtual void executar();

};
