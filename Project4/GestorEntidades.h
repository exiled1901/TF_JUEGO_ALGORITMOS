#pragma once
#include <vector>
#include "Personaje.h"
#include "Perro.h"
#include "Aliado.h"
#include "Objetos.h"
#include "Basura.h"
#include "Elefante.h"
#include "Balas.h"
#include "Barrera.h"
using namespace std;

class GestorEntidades {
private:
	vector<Perro*>listaPerrosH;
	vector<Perro*>listaPerrosV;
	vector<Basura*>listaBasuras;
	vector<Rectangle*>colision2;
	vector<Bala*>listaBalas;
	int ContadorBasuras;
	int contadorBalas;

public:
	GestorEntidades() {
		ContadorBasuras = 0;
		contadorBalas = 0;
	}
	~GestorEntidades() {}

	int getContadorBasuras() { return ContadorBasuras; }
	int getContadorBalas() { return contadorBalas; }
	void setContadorBasuras(int ContadorBasuras) { this->ContadorBasuras = ContadorBasuras; }


	void insertarPerrosH(Perro* p) {
		listaPerrosH.push_back(p);
	}
	void insertarPerrosV(Perro* p) {
		listaPerrosV.push_back(p);
	}
	void dibujarPerros(BufferedGraphics^ bg, Bitmap^ bm) {
		for (int i = 0; i < listaPerrosH.size(); i++)
		{
			listaPerrosH[i]->moverHorizontal(bg, bm);
		}
		for (int i = 0; i < listaPerrosV.size(); i++)
		{
			listaPerrosV[i]->moverVertical(bg, bm);
		}
	}
	void colisionPersonajeBasura(Personaje* jugador, vector<Basura*>& basuras) {
		for (int i = 0; i < basuras.size(); i++) {
			if (basuras.at(i)->getR().IntersectsWith(jugador->getRectangle())) {
				basuras.erase(basuras.begin() + i);
				ContadorBasuras += 1;
			}
		}
	}

	void insertarElefante() {}
	void insertarNaves() {}

	void insertarBalas(Bala* balas) {
		listaBalas.push_back(balas);
	}
	void dibujarBalas(BufferedGraphics^ bg, Bitmap^ ba) {
		for (int i = 0; i < listaBalas.size(); i++)
		{
			listaBalas[i]->moverHorizontal(bg, ba);
		}
	}
	void colisionBarreraBala(Barrera* barrera, vector<Bala*>& balas) {
		for (int i = 0; i < balas.size(); i++) {
			if (balas.at(i)->getR().IntersectsWith(barrera->getRectangle())) {
				balas.erase(balas.begin() + i);
				contadorBalas++;
				//balas[i]->setDibuja(false);
			}

		}

	}

	void insertarBarrera() {
	}

	void insertarBasura(Basura* b) {
		listaBasuras.push_back(b);
	}
	void limpiarArreglo() {
		listaPerrosH.clear();
		listaPerrosV.clear();
	}
	void limpiarArregloBalas(vector<Bala*>& balas) {
		balas.clear();
	}
};