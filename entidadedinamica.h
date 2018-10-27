#pragma once

#include"entidade.h"

class EntidadeDinamica: public Entidade{

protected:

    

public:
  
    EntidadeDinamica(int x, int y, int w, int h, int f);
    EntidadeDinamica();
    ~EntidadeDinamica();
  
    virtual void executar();

};
