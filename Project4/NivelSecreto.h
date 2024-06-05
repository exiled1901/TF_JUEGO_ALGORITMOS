#pragma once
#include "Balas.h"
#include "Barrera.h"
#include "GestorEntidades.h"
#include "Objetos.h"
#include "NewGame.h"
#define ANCHO_PANTALLA 1920
#define ALTO_PANTALLA 1080

using namespace System::Drawing;

class NivelSecreto {
private:
	GestorEntidades* ge = new GestorEntidades();
	// Barrera* barrera = new Barrera(200, 120);
	vector<Bala*> balas;
	vector<Rectangle*> rectangulosColision;
	bool balasAgregar;
	bool terminarNivel;
	bool morirJugador;
	int vidasCerebro;
public:
	NivelSecreto() {
		balasAgregar = false;
		terminarNivel = false;
		morirJugador = false;
		vidasCerebro = 3;

		rectangulosColision.push_back(new Rectangle(1, 199, 292, 900));
		rectangulosColision.push_back(new Rectangle(1, 375, 340, 900));
		rectangulosColision.push_back(new Rectangle(1, 600, 292, 900));
		rectangulosColision.push_back(new Rectangle(1, 199, 292, 900));
		rectangulosColision.push_back(new Rectangle(1, 375, 340, 900));
		rectangulosColision.push_back(new Rectangle(1, 600, 292, 900));
		rectangulosColision.push_back(new Rectangle(1, 199, 292, 900));
		rectangulosColision.push_back(new Rectangle(1, 375, 340, 900));
		rectangulosColision.push_back(new Rectangle(1, 600, 292, 900));
		rectangulosColision.push_back(new Rectangle(1, 199, 292, 900));
		rectangulosColision.push_back(new Rectangle(1, 375, 340, 900));
		rectangulosColision.push_back(new Rectangle(1, 600, 292, 900));
		rectangulosColision.push_back(new Rectangle(1, 199, 292, 900));
		rectangulosColision.push_back(new Rectangle(1, 375, 340, 900));
		rectangulosColision.push_back(new Rectangle(1, 600, 292, 900));
		rectangulosColision.push_back(new Rectangle(0, 0, 1920, 2));
		rectangulosColision.push_back(new Rectangle(0, 1080, 1920, 1081));

		balas.push_back(new Bala(1100, 140));
		balas.push_back(new Bala(1650, 580));
		balas.push_back(new Bala(2200, 380));
		balas.push_back(new Bala(2750, 140));
		balas.push_back(new Bala(3300, 580));
		balas.push_back(new Bala(3850, 380));
		balas.push_back(new Bala(4400, 140));
		balas.push_back(new Bala(4950, 580));
		balas.push_back(new Bala(5500, 380));
		balas.push_back(new Bala(6050, 140));
		balas.push_back(new Bala(6600, 580));
		balas.push_back(new Bala(7150, 380));
		balas.push_back(new Bala(7700, 140));
		balas.push_back(new Bala(8250, 580));
		balas.push_back(new Bala(8800, 380));
		//Parte 2
		balas.push_back(new Bala(9100, 140));
		balas.push_back(new Bala(9400, 580));
		balas.push_back(new Bala(9700, 380));
		balas.push_back(new Bala(10000, 140));
		balas.push_back(new Bala(10300, 580));
		balas.push_back(new Bala(10600, 380));
		balas.push_back(new Bala(10900, 140));
		balas.push_back(new Bala(11200, 580));
		balas.push_back(new Bala(11500, 380));
		balas.push_back(new Bala(11800, 140));
		balas.push_back(new Bala(12598, 580));
		balas.push_back(new Bala(12895, 380));
		balas.push_back(new Bala(13249, 140));
		balas.push_back(new Bala(13549, 580));
		balas.push_back(new Bala(13895, 380));
	}
	~NivelSecreto() { delete ge; }

	bool getTerminarNivel() { return terminarNivel; }
	bool getMorirJugador() { return morirJugador; }
	bool getBasuraAgregar() { return balasAgregar; }

	void setTerminarNivel(bool terminarNivel) { this->terminarNivel = terminarNivel; }
	void setMorirJugador(bool morirJugador) { this->morirJugador = morirJugador; }
	void setBasuraAgregada(bool balasAgregar) { this->balasAgregar = balasAgregar; }

	void moverTodo(BufferedGraphics^ buffer, Bitmap^ ba, Bitmap^ br, Barrera* barrera) {
		for (int i = 0; i < balas.size(); i++) {
			balas.at(i)->moverHorizontal(buffer, ba);
		}

		if (ge->getContadorBalas() == 30)
		{
			terminarNivel = true;
			eliminarVector();
		}
		if (interacciónBalaCerebro(buffer, balas)) {
			morirJugador = true;
		}
	}

	void rectanguloCerebro(BufferedGraphics^ buffer) {
		for (int i = 0; i < rectangulosColision.size(); i++)
		{
			buffer->Graphics->DrawRectangle(gcnew Pen(Color::Blue), *(rectangulosColision.at(i)));
		}
	}

	bool interacciónBalaCerebro(BufferedGraphics^ buffer, vector<Bala*>& balas) {
		bool a = false;
		for (int i = 0; i < rectangulosColision.size(); i++) {
			for (int j = 0; j < balas.size(); j++) {
				if (rectangulosColision.at(i)->IntersectsWith(balas.at(j)->getR())) {
					a = true;
				}
			}
		}
		return a;
	}



	void iniciar(BufferedGraphics^ buffer, Bitmap^ ba, Bitmap^ br, Barrera* barrera) {
		if (terminarNivel == false)
		{
			moverTodo(buffer, ba, br, barrera);
			interacciónBalaCerebro(buffer, balas);


			//rectanguloCerebro(buffer);
			ge->colisionBarreraBala(barrera, balas);

			if (barrera->getVidas() == 0) {
				terminarNivel = true;
			}
			if (terminarNivel == true)
			{
				ge->limpiarArregloBalas(balas);
				barrera->setY(100);
			}
		}
	}

	void eliminarVector() {
		balas.clear();
	}
	void newBalas() {
		Archivo* a = new Archivo();
		vector<int> v_posicionesB;
		v_posicionesB = a->leerPosicionBalas();
		balas.push_back(new Bala(v_posicionesB[0], v_posicionesB[1]));
		balas.push_back(new Bala(v_posicionesB[2], v_posicionesB[3]));
		balas.push_back(new Bala(v_posicionesB[4], v_posicionesB[5]));
		balas.push_back(new Bala(v_posicionesB[6], v_posicionesB[7]));
		balas.push_back(new Bala(v_posicionesB[8], v_posicionesB[9]));
		balas.push_back(new Bala(v_posicionesB[10], v_posicionesB[11]));
		balas.push_back(new Bala(v_posicionesB[12], v_posicionesB[13]));
		balas.push_back(new Bala(v_posicionesB[14], v_posicionesB[15]));
		balas.push_back(new Bala(v_posicionesB[16], v_posicionesB[17]));
		balas.push_back(new Bala(v_posicionesB[18], v_posicionesB[19]));
		balas.push_back(new Bala(v_posicionesB[20], v_posicionesB[21]));
		balas.push_back(new Bala(v_posicionesB[22], v_posicionesB[23]));
		balas.push_back(new Bala(v_posicionesB[24], v_posicionesB[25]));
		balas.push_back(new Bala(v_posicionesB[26], v_posicionesB[27]));
		balas.push_back(new Bala(v_posicionesB[28], v_posicionesB[29]));
		//Parte 2
		balas.push_back(new Bala(v_posicionesB[30], v_posicionesB[31]));
		balas.push_back(new Bala(v_posicionesB[32], v_posicionesB[33]));
		balas.push_back(new Bala(v_posicionesB[34], v_posicionesB[35]));
		balas.push_back(new Bala(v_posicionesB[36], v_posicionesB[37]));
		balas.push_back(new Bala(v_posicionesB[38], v_posicionesB[39]));
		balas.push_back(new Bala(v_posicionesB[40], v_posicionesB[41]));
		balas.push_back(new Bala(v_posicionesB[42], v_posicionesB[43]));
		balas.push_back(new Bala(v_posicionesB[44], v_posicionesB[45]));
		balas.push_back(new Bala(v_posicionesB[46], v_posicionesB[47]));
		balas.push_back(new Bala(v_posicionesB[48], v_posicionesB[49]));
		balas.push_back(new Bala(v_posicionesB[50], v_posicionesB[51]));
		balas.push_back(new Bala(v_posicionesB[52], v_posicionesB[53]));
		balas.push_back(new Bala(v_posicionesB[54], v_posicionesB[55]));
		balas.push_back(new Bala(v_posicionesB[56], v_posicionesB[57]));
		balas.push_back(new Bala(v_posicionesB[58], v_posicionesB[59]));
	}
};