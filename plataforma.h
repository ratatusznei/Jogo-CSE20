#pragma once

class Plataforma: public EntidadeEstatica{

protected:



public:

    Plataforma(int x, int y, int w, int h);
    Plataforma();
    ~Plataforma();
    
    virtual void executar();
    
};
