#pragma once

#include"entidade.h"

class EntidadeDinamica: public Entidade{

protected:



public:
  
    EntidadeDinamica(int x, int y, int w, int h);
    EntidadeDinamica();
    ~EntidadeDinamica();
  
    virtual void executar();

};
