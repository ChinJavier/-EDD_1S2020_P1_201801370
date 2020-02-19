#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string>
class Cuadro
{
public:
	int posX = 0;
	int posY = 0;
	
	Cuadro();
	void setPosX(int);
	void setPosY(int);
	int getPosX();
	int getPosY();

	void menu();
	void editorVacio();
	void Rectangle(int, int, int, int, const char*);
	void ReplicateH(int x, int y, const char* c, int can);
	void ReplicateV(int x, int y, const char* c, int can);
	void Say(int x, int y, const char* txt);
	void Gotoxy(int x, int y);
	void redactar();


};

