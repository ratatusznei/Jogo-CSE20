#pragma once

class EntidadeEstatica: public Entidade{

protected:



public:

    EntidadeEstatica(int x, int y, int w, int h);
    EntidadeEstatica();
    ~EntidadeEstatica();
    
    virtual void executar();
    
};
