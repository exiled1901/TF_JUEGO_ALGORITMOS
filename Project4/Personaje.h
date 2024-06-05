#pragma once
#include "Persona.h"

class Personaje : public Persona {
private:
	bool vidaunica;
public:
	Personaje(int _x, int _y) :Persona(_x, _y, 110, 110, 0, 0) {
		x = _x;
		y = _y;
		vidaunica = false;
	}
	~Personaje() {}
	bool getvidaunica() { return vidaunica; }
	void setvidaunica(bool vidaunica) { this->vidaunica = vidaunica; }
	void mover(BufferedGraphics^ bg, Bitmap^ bm, int a) {
		switch (direccion)
		{
		case Abajo:
			if (a != 3) {
				indiceY = 2;
				if (indiceX >= 0 && indiceX < 3) {
					indiceX++;
				}
				else {
					indiceX = 0;
				}
				dx = 0;
				dy = 15;
				ultimaTecla = Abajo;
			}
			break;
		case Arriba:
			if (a != 3) {
				indiceY = 0;
				if (indiceX >= 0 && indiceX < 3) {
					indiceX++;
				}
				else {
					indiceX = 0;
				}
				dx = 0;
				dy = -15;
				ultimaTecla = Arriba;
			}
			break;
		case Izquierda:
			if (a != 3) {
				indiceY = 1;
				if (indiceX >= 0 && indiceX < 3) {
					indiceX++;
				}
				else {
					indiceX = 0;
				}
				dx = -15;
			}
			else if (a == 3) {
				indiceY = 0;
				if (indiceX >= 0 && indiceX < 4) {
					indiceX++;
				}
				else {
					indiceX = 0;
				}
				dx = -9;

			}
			dy = 0;
			ultimaTecla = Izquierda;
			break;
		case Derecha:
			if (a != 3) {
				indiceY = 3;
				if (indiceX >= 0 && indiceX < 3) {
					indiceX++;
				}
				else {
					indiceX = 0;
				}
				dx = 15;
			}
			else if (a == 3) {
				indiceY = 1;
				if (indiceX >= 0 && indiceX < 4) {
					indiceX++;
				}
				else {
					indiceX = 0;
				}
				dx = 9;
			}
			dy = 0;
			ultimaTecla = Derecha;
			break;
		case Ninguna:
			dx = 0;
			dy = 0;
			if (a != 3) {
				switch (ultimaTecla)
				{
				case Abajo:
					indiceY = 2;
					indiceX = 0;
					break;
				case Arriba:
					indiceY = 0;
					indiceX = 0;
					break;
				case Izquierda:
					indiceY = 1;
					indiceX = 0;
					break;
				case Derecha:
					indiceY = 3;
					indiceX = 0;
					break;
				}
			}
			else if (a == 3) {
				switch (ultimaTecla)
				{
				case Izquierda:
					indiceY = 0;
					indiceX = 0;
					break;
				case Derecha:
					indiceY = 1;
					indiceX = 0;
					break;
				}
			}
			else if (a == 3) {
				switch (ultimaTecla) {
				case Izquierda:
					indiceY = 0;
					indiceX = 0;
					break;
				case Derecha:
					indiceY = 1;
					indiceX = 0;
					break;

				}
			}
		}
		if (a == 1) {
			dibujar_nivel_1(bg, bm);
		}
		else if (a == 2) {
			r = Rectangle(x + 40, y + 80, 30, 28);
			dibujar(bg, bm);
		}
		else if (a == 3) {
			ancho = 60; alto = 50;
			r = Rectangle(x, y, 60 * 3, 50 * 3);
			dibujar_nivel_3(bg, bm);
		}
	}

};
