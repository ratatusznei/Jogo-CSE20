#pragma once

template <class T>
class Queue{

protected:

    T* head;
    T* tail;
    
public:

    Queue(){
    
        tail = head;
        
    }
    ~Queue(){
    
        tail = head;
        
    }
    void enqueue(T elemento){
    
        tail = &elemento;
        tail++;
        
    }
    T dequeue(){
    
        if(tail == head)
            return NULL;
        else{
        
            T aux = *head;
            head++;
            return aux;
        
        }
    }

};
