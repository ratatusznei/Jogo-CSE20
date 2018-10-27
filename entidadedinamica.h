#pragma once

#include"entidade.h"

class EntidadeDinamica: public Entidade{

protected:

    Vetor<double> velocidade;
    Vetor<double> aceleracao;
    int direcao;

public:
  
    EntidadeDinamica(int x, int y, int w, int h, int f);
    EntidadeDinamica();
    ~EntidadeDinamica();
    
    void setvel(Vetor<double> v);
    void setvel(double vx, double vy);
    Vetor<double> getvel();
   
    void setace(Vetor<double> a);
    void setace(double ax, double ay);
    Vetor<double> getace();
    
    void setdirecao(int d);
    int getdirecao();
  
    virtual void andar();
    virtual void atacar();
    virtual void executar();

};
