#pragma once
#include "Enemigos.h"
class Bus :public Enemigos {
private:
	int contadorMovimiento;
	int contadorMovimiento2;
public:
	Bus(int x, int y) :Enemigos(x, y, 360, 202, 5, 5)
	{
		this->x = x; this->y = y; contadorMovimiento = 0; contadorMovimiento2 = 0;
	}
	~Bus() {}
	void setcontadormovimiento(int contadorMovimiento) { this->contadorMovimiento = contadorMovimiento; }
	void setcontadorMovimiento2(int contadorMovimiento2) { this->contadorMovimiento2 = contadorMovimiento2; }
	int getcontadormovimiento() { return contadorMovimiento; }
	int getcontadormovimiento2() { return contadorMovimiento2; }
	void moverVertical(BufferedGraphics^ bg, Bitmap^ bf) {}
	void moverHorizontal(BufferedGraphics^ bg, Bitmap^ bm) {


		if (contadorMovimiento < 250) {
			indiceY = 0;
			if (indiceX < 2) {
				indiceX++;
			}
			else {
				indiceX = 0;
			}
			dx = -18;
			dy = 0;
			contadorMovimiento++;
		}

		Rectangle h = Rectangle(x, y, 360 * 1.5, 205*1.5);
		setR(h);
		dibujar(bg, bm);

	}
};