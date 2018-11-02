#pragma once

template <class T = double> class Vetor{

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

    void operator = (Vetor<T>& v){

        x = v.getx();
        y = v.gety();

    }
    Vetor<T>& operator * (double escalar){

        x *= escalar;
        y *= escalar;

    }
    void operator ()(T xis, T ipsilon){

        x = xis;
        y = ipsilon;

    }

};
