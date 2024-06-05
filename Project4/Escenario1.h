#pragma once
#include "Personaje.h"

using namespace System;
using namespace System::Drawing;

class Escenario1 {
private:
	vector<Rectangle*> escenario;
	Rectangle pelota;
	Rectangle album;
	Rectangle videojuego;
	Rectangle carta;
	Rectangle almohada1;
	Rectangle almohada2;
	Rectangle almohada3;
	Rectangle pantalla;
public:
	Escenario1() {
		//Refrigeradora
		escenario.push_back(new Rectangle(0, 0, 180, 400));
		//Cocina
		escenario.push_back(new Rectangle(180, 0, 480, 400));
		//Puerta y pared
		escenario.push_back(new Rectangle(660, 0, 1980 - 660, 300));
		//Radio?
		escenario.push_back(new Rectangle(1240, 150, 288, 285));
		//Chimenea
		escenario.push_back(new Rectangle(1680, 50, 288, 426));
		//Mesa
		escenario.push_back(new Rectangle(315, 930, 300, 130));
		// Pantalla
		escenario.push_back(new Rectangle(0, 0, -1, 1080));
		escenario.push_back(new Rectangle(0, 1080, 1920, 1081));
		escenario.push_back(new Rectangle(1920, 0, 1921, 1080));
		//Pelota de futbol
		pelota = Rectangle(750, 685, 100, 110);
		//Album
		album = Rectangle(1255, 810, 125, 90);
		//Videojuego
		videojuego = Rectangle(1540, 900, 120, 150);
		//Carta
		carta = Rectangle(1020, 330, 60, 60);
		//Almohada1
		almohada1 = Rectangle(20, 630, 200, 140);
		//Almohada1
		almohada2 = Rectangle(955, 980, 255, 140);
		//Almohada1
		almohada3 = Rectangle(1730, 610, 200, 140);

	}
	~Escenario1() {}
	void rectangulosLimites(BufferedGraphics^ buffer) {
		for (int i = 0; i < escenario.size(); i++)
		{
			buffer->Graphics->DrawRectangle(gcnew Pen(Color::Green, 2), *(escenario.at(i)));
		}
		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Red, 2), pelota);
		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Blue, 2), album);
		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Red, 2), videojuego);
		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Red, 2), carta);
		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Red, 2), almohada1);
		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Red, 2), almohada2);
		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Red, 2), almohada3);
	}
	void iniciar(BufferedGraphics^ buffer, Personaje* jugador) {
		//rectangulosLimites(buffer);
		colisionRecuerdos(jugador);
		interacciónPersonajeLimites(jugador, buffer);
	}

	void interacciónPersonajeLimites(Personaje* jugador, BufferedGraphics^ bg) {
		Rectangle r2 = Rectangle(jugador->getX() + jugador->getdx() + 80, jugador->getY() + jugador->getdy() + 160, 60, 56);
		//bg->Graphics->DrawRectangle(gcnew Pen(Color::Blue), r2);
		for (int i = 0; i < escenario.size(); i++)
		{
			if ((escenario.at(i)->IntersectsWith(r2))) {
				jugador->setdx(0); jugador->setdy(0);
			}
			else {

			}

		}
	}

	int colisionRecuerdos(Personaje* jugador) {
		int a = 0;
		if (pelota.IntersectsWith(jugador->getRectangle())) {
			a = 1;
		}
		else if (album.IntersectsWith(jugador->getRectangle())) {
			a = 2;
		}
		else if (videojuego.IntersectsWith(jugador->getRectangle())) {
			a = 3;
		}
		else if (carta.IntersectsWith(jugador->getRectangle())) {
			a = 4;
		}
		else if (almohada1.IntersectsWith(jugador->getRectangle())) {
			a = 5;
		}
		else if (almohada2.IntersectsWith(jugador->getRectangle())) {
			a = 6;
		}
		else if (almohada3.IntersectsWith(jugador->getRectangle())) {
			a = 7;
		}
		return a;
	}
	 

};