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
    void operator = (T xis, T ipsilon){
        
        x = xis;
        y = ipsilon;
        
    }
    Vetor operator + (Vetor& v1, Vetor& v2){
        
        x = v1.getx() + v2.getx();
        y = v1.gety() + v2.gety();
        
    }
    void operator += (Vetor& v){
        
        x = x + v.getx();
        y = y + v.gety();
        
    }
    Vetor operator * (Vetor& v, double escalar){
        
        x = v.getx() * escalar;
        y = v.gety() * escalar;
        
    }
    double operator * (Vetor& v1, Vetor& v2){
        
        return v1.getx()*v2.getx() + v1.gety()*v2.gety();
        
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
    /*bool operator > (Vetor& v){
        
        if (this * this > v * v)
            return true;
        else
            return false;
        
    }*/
    

};
