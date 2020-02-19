#include "ListaDobleEnlazada.h"
#include <iostream>
#include <string>
using namespace std;

ListaDobleEnlazada::ListaDobleEnlazada() {
	this->primero = NULL;
	this->ultimo = NULL;
	this->tamanio = 0;
}


void ListaDobleEnlazada::setTamanio(int tamanio) {
	this->tamanio = tamanio;
}

int ListaDobleEnlazada::getTamanio() {
	return this->tamanio;
}

Nodo_D_E* ListaDobleEnlazada::getPrimero() {
	return this->primero;
}

Nodo_D_E* ListaDobleEnlazada::getUltimo() {
	return this->ultimo;
}

bool ListaDobleEnlazada::estaVacia() {
	bool bandera = false;
	if (this->primero == NULL)
	{
		bandera = true;
		return bandera;
	}
	return bandera;
}

void ListaDobleEnlazada::insertarFinal(char c, int x, int y) {
	Nodo_D_E* nuevo = new Nodo_D_E();
	nuevo->setCaracter(c);
	nuevo->setxPos(x);
	nuevo->setyPos(y);
	if (ListaDobleEnlazada::estaVacia())
	{
		this->primero = nuevo;
		this->ultimo = nuevo;

	}
	else {
		this->ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(this->ultimo);
		this->ultimo = nuevo;
	}
}

void ListaDobleEnlazada::imprimir() {
	int col = 0;
	Nodo_D_E* aux = this->primero;
	while (aux!=NULL) {
		cout << aux->getCaracter();
		aux = aux->getSiguiente();
		if (col>82)
		{
			col = 0;
			cout << "\n";
			cout << "                ";
		}
		col++;
	}
}

string ListaDobleEnlazada::codigoGraph() {
	string diagr = "digraph G ";
	string acumulador = diagr + "{ style = filled; color = lightgrey; node[color = black]; " + '\n';
	string acumulador2 = " ";
	int indice = 0;
	int indice2 = 1;

	Nodo_D_E* aux = this->primero;
	while (aux->getSiguiente() != NULL) {
		acumulador2 += aux->getCaracter() + to_string(indice) + "->" + aux->getSiguiente()->getCaracter() + to_string(indice2) + ";";
		acumulador2 += aux->getSiguiente()->getCaracter() + to_string(indice2) + "->" + aux->getCaracter() + to_string(indice) + ";";
		indice++;
		indice2++;
		aux = aux->getSiguiente();

	}
	acumulador += acumulador2 + "}";

	return acumulador;
}

Nodo_D_E* ListaDobleEnlazada::Buscar(int x, int y) {
	if (this->primero != NULL) { //Quiere decir que no está vacia
		Nodo_D_E* aux = this->primero; //Creo un nodo auxiliar
		while (aux != NULL) {
			if (x == aux->getxPos() && y == aux->getyPos()) {
				return aux;
			}
			aux = aux->getSiguiente();
		}
	}
	Nodo_D_E* vacio = new Nodo_D_E();
	return vacio;
}

void ListaDobleEnlazada::eliminar(Nodo_D_E*& nodo) {
	Nodo_D_E*& aux = this->primero;

	if (this->primero != NULL) { //Si la lista no está vacia

		if (this->primero == this->ultimo) { //Si solo tengo un elemento
			aux = NULL;
			this->primero = NULL;
			this->ultimo = NULL;
		}
		else if (this->ultimo == nodo) {// elimina ultimo 
			this->ultimo = this->ultimo->getAnterior();
			this->ultimo->setSiguiente(NULL);
		}

	}
}

string ListaDobleEnlazada::imprimirContenido() {
	string contenido = "";
	int col = 0;
	Nodo_D_E* aux = this->primero;
	while (aux != NULL) {
		contenido += aux->getCaracter();
		aux = aux->getSiguiente();
		if (col > 82)
		{
			col = 0;
			contenido += "\n";
			cout << "                ";
		}
		col++;
	}
	return contenido;
}