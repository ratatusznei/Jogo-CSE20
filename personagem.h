#pragma once

#include"entidadedinamica.h"

class Personagem: public EntidadeDinamica{

protected:



public:

    Personagem(int x, int y, int w, int h, Vetor<double> v, Vetor<double> a, Direcao d);
    Personagem();
    ~Personagem();
    
    virtual void andar();
    virtual void atacar();
    virtual void executar();

};
