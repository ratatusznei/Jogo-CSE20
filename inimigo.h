#pragma once

#include"entidadedinamica.h"

class Inimigo{

protected:



public:

    Inimigo(int x, int y, int w, int h);
    Inimigo();
    ~Inimigo();
    
    virtual void atacar();
    virtual void andar();
    virtual void executar();

};
