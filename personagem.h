#pragma once

#include"entidade.h"

class Personagem: public Entidade{

protected:



public:
  
    Personagem(int x, int y, int w, int h);
    Personagem();
    ~Personagem();
  
    virtual void executar();

};
