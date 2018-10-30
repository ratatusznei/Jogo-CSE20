#pragma once

#include"entidade.h"

enum class Direcao {left, right};

class EntidadeDinamica: public Entidade{

protected:

    Vetor<double> velocidade;
    Vetor<double> aceleracao;
    Direcao dir;

public:
  
    EntidadeDinamica(int x, int y, int w, int h, Vetor<double> v, Vetor<double> a, Direcao d);
    EntidadeDinamica();
    ~EntidadeDinamica();
    
    void setvel(Vetor<double> v);
    void setvel(double vx, double vy);
    Vetor<double> getvel();
   
    void setace(Vetor<double> a);
    void setace(double ax, double ay);
    Vetor<double> getace();
    
    void setdirecao();
  
    virtual void andar();
    virtual void atacar();
    virtual void executar();

};
