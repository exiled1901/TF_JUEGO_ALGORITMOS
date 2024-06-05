#pragma once
#include "Enemigos.h"

class Basura : public Objetos {
private:
	int contadorMovimiento;
	int contadorMovimiento2;
public:
	Basura(int _x, int _y);
	~Basura();
	void mover(BufferedGraphics^ bg, Bitmap^ bm);
	


};

Basura::Basura(int _x, int _y) : Objetos(_x, _y, 44, 44) {
	x = _x;
	y = _y;
	contadorMovimiento = 0;
	contadorMovimiento2 = 0;
}

Basura::~Basura() {}

void Basura::mover(BufferedGraphics^ bg, Bitmap^ bm) {
	indiceY = 0;
	if (indiceX < 7)
	{
		indiceX++;
	}
	else
	{
		indiceX = 0;
	}
	Rectangle h = Rectangle(x + 8, y + 2, 44, 48);
	setR(h);
	dibujar(bg, bm);
}