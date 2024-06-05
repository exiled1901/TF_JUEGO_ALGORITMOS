#pragma once
#include "Personaje.h"
#include "Enemigos.h"

class Elefante : public Enemigos {
private:
	int contadorMovimiento;
	int contadorMovimiento2;
public:
	Elefante(int _x, int _y);
	~Elefante();
	void moverHorizontal(BufferedGraphics^ bg, Bitmap^ bm);
	void moverVertical(BufferedGraphics^ bg, Bitmap^ bm);
	void colisionPersonaje(Personaje* jugador, Elefante* pr) {
		if (pr->getR().IntersectsWith(jugador->getRectangle())) {
			jugador->setvidaunica(true);
		}
	}
};

Elefante::Elefante(int _x, int _y) : Enemigos(_x, _y, 96, 96, 0, 0) {
	x = _x;
	y = _y;
	contadorMovimiento = 0;
	contadorMovimiento2 = 0;
}

Elefante::~Elefante() {}
void Elefante::moverHorizontal(BufferedGraphics^ bg, Bitmap^ bf) {}
void Elefante::moverVertical(BufferedGraphics^ bg, Bitmap^ bf) {


	if (contadorMovimiento < 25) {
		indiceY = 2;
		if (indiceX < 2) {
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
		if (contadorMovimiento2 < 25)
		{
			indiceY = 0;
			if (indiceX < 2)
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
		if (contadorMovimiento2 == 25) {
			contadorMovimiento = 0;
		}
	}
	Rectangle h = Rectangle(x, y +13, 110, 100);
	setR(h);
	dibujar(bg, bf);
}
