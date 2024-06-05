#pragma once
#include "Bus.h"
#include "NewGame.h"
#define ANCHO_PANTALLA 1920
#define ALTO_PANTALLA 1080

using namespace System::Drawing;

class Escenario3 {
private:
	Bus* bus = new Bus(1920, 400);
	vector<Rectangle*>rectangulosColision;
public:
	Escenario3() {
		
		rectangulosColision.push_back(new Rectangle(0, 0, 1, 1080));
	}
	~Escenario3() {	}

	void moverTodo(BufferedGraphics^ buffer, Bitmap^ bl) {
		bus->moverHorizontal(buffer, bl);
	}

	void iniciar(BufferedGraphics^ buffer, Personaje* jugador, Bitmap^ bl) {
		colisionPersonajeEscenario(jugador, buffer);
		moverTodo(buffer, bl);
		colisionPersonajeCarro(jugador);
		distanciaCarro(jugador);
	}

	bool colisionPersonajeEscenario(Personaje* jugador, BufferedGraphics^ bg) {
		bool a = false;
		for (int i = 0; i < rectangulosColision.size(); i++)
		{

			if (rectangulosColision.at(i)->IntersectsWith(jugador->getRectangle())) {
				a = true;

			}
		}
		return a;
	}

	bool colisionPersonajeCarro(Personaje* jugador) {
		bool a = false;
		if (jugador->getRectangle().IntersectsWith(bus->getR())) {
			a=true;
		}
		return a;
	}

	bool distanciaCarro(Personaje* jugador) {
		bool a = false;
		if (bus->getX() - (jugador->getX() + 60) < 700) {
			a = true;
		}
		return a;
	}
	void reiniciarBus() {
		Archivo* a = new Archivo();
		vector<int> v_bus;
		v_bus = a->leerPosicionInicial();
		bus->setXY(v_bus[8], v_bus[9]);
		bus->setcontadormovimiento(v_bus[10]);
		bus->setcontadorMovimiento2(v_bus[11]);
	}
};