#pragma once
#include <iostream>
#include <string>
#include "Nodo_D_E.h"
using namespace std;


class ListaDobleEnlazada
{

private:
	Nodo_D_E* primero;
	Nodo_D_E* ultimo;
	int tamanio;
	

public:

	ListaDobleEnlazada();	 //Constructor
	void insertarFinal(char c, int, int); //Utilizado para insertar al teclear
	Nodo_D_E* Buscar(int, int);
	void eliminar(Nodo_D_E*& n); //Utilizado para cuando le de delete
	void reemplazar(); //Aún está en proceso
	bool estaVacia(); //Indica si está vacia
	void imprimir(); //Imprime los valores en la lista
	string codigoGraph();
	string imprimirContenido();

	void setTamanio(int);

	Nodo_D_E* getPrimero(); 
	Nodo_D_E* getUltimo();
	int getTamanio();


	
};

