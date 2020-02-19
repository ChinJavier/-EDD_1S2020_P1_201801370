#include "Cuadro.h"
#include <conio.h>
#include <iostream>
#include "ListaDobleEnlazada.h"
#include <fstream>
using namespace std;


static ListaDobleEnlazada listaDobleEnlazada;

Cuadro::Cuadro() {
	this->posX = 0;
	this->posY = 0;
}

void Cuadro::setPosX(int x) {
	this->posX = x;
}

void Cuadro::setPosY(int y) {
	this->posY = y;
}

int Cuadro::getPosX(){
	return this->posX;
}
int Cuadro::getPosY() {
	return this->posY;
}

void Cuadro::menu() {
	system("cls");
	int opcion = 0;
	cout << endl;
	cout << "				UNIVERSIDAD DE SAN CARLOS DE GUATEMALA" << endl;
	cout << "				FACULTAD DE INGENIERIA" << endl;
	cout << "				ESTRUCTURA DE DATOS" << endl;
	cout << "				PRACTICA 1" << endl;
	cout << "				Javier Antonio Chin Flores" << endl;
	cout << "				201801370" << endl;
	cout << "**********************************************************************************************" << endl;
	cout << "				MENU" << endl;
	cout << "				1. Crear Archivo" << endl;
	cout << "				2. Abrir Archivo" << endl;
	cout << "				3. Archivos Recientes" << endl;
	cout << "				4. Salir" << endl;
	cout << "***********************************************************************************************" << endl;
	cout << "				Ingrese la opcion deseada " << endl;
	cin >> opcion;
	if (opcion ==1)
	{
		system("cls");
		Cuadro::editorVacio();
		Cuadro::Gotoxy(18, 26);
		Cuadro::redactar();
	}
	else if (opcion == 2)
	{
		string rutaOp2 = " ";
		system("cls");
		cout << "Ingrese la ruta";
		cin >> rutaOp2;
	}
	else if (opcion == 3)
	{

	}
	else if (opcion == 4)
	{
		cout << "¡HASTA LA PROXIMA!"<<endl;
		system("pause");
	}
	else {
		cout << "DIGITE UNA OPCION CORRECTA" << endl;
		Cuadro::menu();
	}


}


void Cuadro::editorVacio() {
	Cuadro::Rectangle(15, 2, 85, 22, "*");
}


void Cuadro::redactar() {
	ofstream escribe;
	escribe.open("C:\\EDD\\dE.txt", ios::out);
	if (escribe.fail())
	{
		cout << "*No se pudo abrir el archivo*"<<endl;
		system("pause");
		exit(1);
	}

	int valorAscci = 0;
	char entrada = ' ';
	bool band = true;
	int inicialX = 16;
	int inicialY = 3;
	int x = 16;
	int y = 3;
	string name = "";
	while (band)
	{
		Gotoxy(x, y);
		entrada = _getch();
		valorAscci = entrada;

		if (valorAscci == 8) //Si quiero borrar
		{
			if (x > 16)
			{

				Gotoxy(x--, y);
				Nodo_D_E* encontrado = listaDobleEnlazada.Buscar(x,y);
				listaDobleEnlazada.eliminar(encontrado);
				//cout << "El encontrado es: " << encontrado->getCaracter();
				//system("pause");
			}
			else {
				x = 98;
				Gotoxy(x, y--);
			}
			
		}
		else { //Si no quiero borrar
			if (valorAscci == 32 || valorAscci == 9 || valorAscci == 13) //Si es espacio, tab o enter no hago nada
			{
				listaDobleEnlazada.insertarFinal(' ', x, y);
			}
			else if (valorAscci == 3 || valorAscci == 19)
			{

			}
			else {
				listaDobleEnlazada.insertarFinal(entrada, x, y);
			}
			Gotoxy(x, y);
			x++;
		}
		if (valorAscci == 3) { //Generar el codigoGraph
			escribe<<listaDobleEnlazada.codigoGraph();
			escribe.close();
			char g[] = "dot -Tjpg C:\\EDD\\dE.txt -o C:\\EDD\\dE.jpg";
			system(g);
			char e[] = "C:\\EDD\\dE.jpg";
			system(e);
			band = false;
			system("pause");
			menu();
		}
		if (valorAscci == 19) { //Guardar el archivo
			string ruta = "C:\\EDD\\";
			cout << "Ingrese el nombre";
			cin >> name;
			ruta = ruta + name + ".txt";
			ofstream escribe2;
			escribe2.open(ruta, ios::out);
			if (escribe2.fail())
			{
				cout << "*No se pudo abrir el archivo*" << endl;
				system("pause");
				exit(1);
			}
			escribe2 << listaDobleEnlazada.imprimirContenido();

			escribe2.close();
			band = false;
			system("pause");
			menu();
		}


		system("cls");
		Gotoxy(inicialX, inicialY);
		listaDobleEnlazada.imprimir();
		if (x > 98)
		{
			x = 16;
			y++;
		}
		Cuadro::editorVacio();
		
	}
}


void Cuadro::Gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void Cuadro::Say(int x, int y, const char* txt)
{
	Gotoxy(x, y); printf("%s", txt);
}

void Cuadro::ReplicateH(int x, int y, const char* c, int total)
{
	for (int i = 0; i < total; i++)
	{
		Say(x + i, y, c);
	}
}

void Cuadro::ReplicateV(int x, int y, const char* c, int can)
{
	for (int i = 0; i < can; i++)
	{
		Say(x, y + i, c);
	}
}

void Cuadro::Rectangle(int x, int y, int w, int h, const char* c)
{
	Cuadro::ReplicateH(x, y, c, w);//fila 1
	Cuadro::ReplicateH(x, y + h, c, w);//fila 2
	Cuadro::ReplicateV(x, y, c, h);//col 1
	Cuadro::ReplicateV(x + w - 1, y, c, h);//col 2
	cout << endl;
	cout << endl;
	cout << "		  ^w(Buscar y remplazar)	    ^c(Reportes)		     ^s(Guardar)" << endl;
	cout << endl;

}


