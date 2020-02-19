#include "Nodo_D_E.h"

Nodo_D_E::Nodo_D_E() {};
Nodo_D_E::Nodo_D_E(char c, int x, int y) {
	this->caracter = c;
	this->anterior = 0;
	this->siguiente = 0;
	this->xPos = x;
	this->yPos = y;
}

void Nodo_D_E::setxPos(int x) {
	this->xPos = x;
}

void Nodo_D_E::setyPos(int y) {
	this->yPos = y;
}

void Nodo_D_E::setCaracter(char c) {
	this->caracter = c;
}
void Nodo_D_E::setSiguiente(Nodo_D_E* sig) {
	this->siguiente = sig;
}
void Nodo_D_E::setAnterior(Nodo_D_E* ant) {
	this->anterior = ant;
}

char Nodo_D_E::getCaracter() {
	return this->caracter;
}

int Nodo_D_E::getxPos() {
	return this->xPos;
}

int Nodo_D_E::getyPos() {
	return this->yPos;
}

Nodo_D_E* Nodo_D_E::getSiguiente() {
	return this->siguiente;
}
Nodo_D_E* Nodo_D_E::getAnterior() {
	return this->anterior;
}