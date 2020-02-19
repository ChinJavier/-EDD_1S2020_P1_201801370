#pragma once
#include <iostream>

class Nodo_D_E
{

private:
    int xPos;
    int yPos;
    char caracter;  
    Nodo_D_E* siguiente;
    Nodo_D_E* anterior;

public:
    Nodo_D_E();
    Nodo_D_E(char c, int, int);
    
    void setCaracter(char c);
    void setSiguiente(Nodo_D_E*);
    void setAnterior(Nodo_D_E*);
    void setxPos(int);
    void setyPos(int);

    int getxPos();
    int getyPos();
    char getCaracter();
    Nodo_D_E* getSiguiente();
    Nodo_D_E* getAnterior();

};

