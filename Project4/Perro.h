#pragma once
#include "Enemigos.h"

class Perro : public Enemigos {
private:
	int contadorMovimiento;
	int contadorMovimiento2;
	bool desaparecer;
public:
	Perro(int _x, int _y);
	~Perro();
	void setDesaparecer(bool desaparecer) { this->desaparecer = desaparecer; }
	bool getDesaparecer() { return this->desaparecer; }
	void moverHorizontal(BufferedGraphics^ bg, Bitmap^ bm);
	void moverVertical(BufferedGraphics^ bg, Bitmap^ bm);
	void colisionPersonaje(Personaje* jugador, Perro* pr) {
		if (pr->getR().IntersectsWith(jugador->getRectangle())) {
			jugador->setvidaunica(true);
		}
	}
};

Perro::Perro(int _x, int _y) : Enemigos(_x, _y, 110, 90, 0, 0) {
	x = _x;
	y = _y;
	contadorMovimiento = 0;
	contadorMovimiento2 = 0;
	desaparecer = true;
}

Perro::~Perro() {}

void Perro::moverHorizontal(BufferedGraphics^ bg, Bitmap^ bm) {


	if (contadorMovimiento < 30) {
		indiceY = 6;
		if (indiceX < 11) {
			indiceX++;
		}
		else {
			indiceX = 0;
			contadorMovimiento2 = 0;
		}
		dx = 10;
		dy = 0;
		contadorMovimiento++;
	}
	else
	{
		if (contadorMovimiento2 < 30)
		{
			indiceY = 7;
			if (indiceX < 11)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;

			}
			contadorMovimiento2++;
		}

		dx = -10;
		dy = 0;
		if (contadorMovimiento2 == 30) {
			contadorMovimiento = 0;
		}
	}
	Rectangle h = Rectangle(x + 10, y + 78, 110 * 1.3, 25);
	setR(h);
	dibujar(bg, bm);

}
void Perro::moverVertical(BufferedGraphics^ bg, Bitmap^ bm) {


	if (contadorMovimiento < 30) {
		indiceY = 10;
		if (indiceX < 11) {
			indiceX++;
		}
		else {
			indiceX = 0;
			contadorMovimiento2 = 0;
		}
		dx = 0;
		dy = 10;
		contadorMovimiento++;
	}
	else
	{
		if (contadorMovimiento2 < 30)
		{
			indiceY = 11;
			if (indiceX < 11)
			{
				indiceX++;
			}
			else
			{
				indiceX = 0;

			}
			contadorMovimiento2++;
		}

		dx = 0;
		dy = -10;
		if (contadorMovimiento2 == 30) {
			contadorMovimiento = 0;
		}
	}
	Rectangle h = Rectangle(x + 60, y + 20, 110 * 0.4, 100);
	setR(h);
	dibujar(bg, bm);
}


