#pragma once
#include "Persona.h"

using namespace System::Drawing;

class Barrera : public Persona {
	int vidas;

public:
	Barrera(int _x, int _y) : Persona(_x, _y, 80, 200, 0, 0) {
		x = _x;
		y = _y;
		vidas = 3;
	}

	~Barrera() {}

	int getVidas() {
		return vidas;
	}
	void setVidas(int vidas) {
		this->vidas = vidas;
	}


	void mover(BufferedGraphics^ bg, Bitmap^ bm, int a) {
		switch (direccion)
		{
		case Abajo:
			dx = 0;
			dy = 50;
			break;

		case Arriba:
			dx = 0;
			dy = -50;
			break;

		default:
			break;
		}

		dibujar_nivel_secreto(bg, bm);
	}
};