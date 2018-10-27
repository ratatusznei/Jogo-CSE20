#pragma once

template <class T>
class Vetor{

protected:

    T x;
    T y;

public:

    Vetor(T xis, T ipsilon){

        x = xis;
        y = ipsilon;

    }
    Vetor(){

        x = 0;
        y = 0;

    }
    ~Vetor(){}

    void setx(T xis){
        x = xis;
    }
    T getx(){
        return x;
    }

    void sety(T ipsilon){
        y = ipsilon;
    }
    T gety(){
        return y;
    }

    void operator = (Vetor& v){

        x = v.getx();
        y = v.gety();

    }
    Vetor operator + (Vetor& v){

        Vetor<T> aux;
        aux.setx(x+v.getx());
        aux.sety(y+v.gety());
        return aux;

    }
    void operator += (Vetor& v){

        x = x + v.getx();
        y = y + v.gety();

    }
    Vetor operator * (double escalar){

        Vetor<T> aux;
        aux.setx(x*escalar);
        aux.sety(y*escalar);
        return aux;

    }
    T operator * (Vetor& v){

        return x*v.getx() + y*v.gety();

    }
    void operator *= (double escalar){

        x = x * escalar;
        y = y * escalar;

    }
    bool operator == (Vetor& v){

        if (x == v.getx() && y == v.gety())
            return true;
        else
            return false;

    }
    bool operator != (Vetor& v){

        if (x == v.getx() && y == v.gety())
            return false;
        else
            return true;

    }
    bool operator > (Vetor& v){

        if ((x*x+y*y) > v * v)
            return true;
        else
            return false;

    }
    bool operator >= (Vetor& v){

        if ((x*x+y*y) >= v * v)
            return true;
        else
            return false;

    }
    bool operator < (Vetor& v){

        if ((x*x+y*y) < v * v)
            return true;
        else
            return false;

    }
    bool operator <= (Vetor& v){

        if ((x*x+y*y) <= v * v)
            return true;
        else
            return false;

    }

};
