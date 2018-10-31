#pragma once

#include"entidadedinamica.h"

class Personagem: public EntidadeDinamica{

protected:



public:

    Personagem(Vetor<int> , int w, int h, Vetor<> v, Vetor<> a, Direcao d);
    Personagem(int x, int y, int w, int h);
    Personagem();
    ~Personagem();
    
    virtual void andar();
    virtual void atacar();
    virtual void executar();

};
