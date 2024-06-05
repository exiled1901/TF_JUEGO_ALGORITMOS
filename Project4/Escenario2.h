#pragma once
#include "Perro.h"
#include "Basura.h"
#include "Aliado.h"
#include "Personaje.h"
#include "Elefante.h"
#include "GestorEntidades.h"
#include "Objetos.h"
#include "NewGame.h"
#define ANCHO_PANTALLA 1920
#define ALTO_PANTALLA 1080

using namespace System::Drawing;

class Escenario2 {
private:
	GestorEntidades* ge = new GestorEntidades();
	Perro* lobo = new Perro(650, 720); //LISTO
	Perro* lobo1 = new Perro(1290, 730); //LISTO
	Perro* lobo2 = new Perro(1250, 10);//LISTO
	Aliado* aliado = new Aliado(1300, 1);
	Elefante* elf = new Elefante(1700, 300);
	vector<Basura*> basuras;
	vector<Rectangle*>rectangulosColision;
	bool basuraagregada;
	bool terminarnivel;
	bool morirjugador;
	bool desaparecerlobos;
	bool morirlobos;
	bool reiniciarbasuras;
public:
	Escenario2() {
		basuraagregada = false;
		terminarnivel = false;
		morirjugador = false;
		desaparecerlobos = false;
		morirlobos = false;
		ge->insertarPerrosH(lobo);
		ge->insertarPerrosH(lobo1);
		ge->insertarPerrosV(lobo2);
		rectangulosColision.push_back(new Rectangle(1, 1, 850, 230));
		rectangulosColision.push_back(new Rectangle(851, 1, 260, 140));
		rectangulosColision.push_back(new Rectangle(1111, 80, 180, 240));
		rectangulosColision.push_back(new Rectangle(1380, 120, 115, 125));
		rectangulosColision.push_back(new Rectangle(1495, 1, 424, 330));
		rectangulosColision.push_back(new Rectangle(1810, 331, 109, 110));
		rectangulosColision.push_back(new Rectangle(1600, 880, 319, 128));
		rectangulosColision.push_back(new Rectangle(1750, 750, 169, 125));
		rectangulosColision.push_back(new Rectangle(1, 943, 1599, 65));
		rectangulosColision.push_back(new Rectangle(900, 878, 610, 65));
		rectangulosColision.push_back(new Rectangle(1, 231, 200, 350));
		rectangulosColision.push_back(new Rectangle(1, 581, 300, 361));
		rectangulosColision.push_back(new Rectangle(460, 761, 190, 181));
		rectangulosColision.push_back(new Rectangle(340, 442, 125, 128));
		rectangulosColision.push_back(new Rectangle(800, 442, 125, 235));
		rectangulosColision.push_back(new Rectangle(930, 262, 100, 130));
		rectangulosColision.push_back(new Rectangle(1380, 475, 190, 240));
		rectangulosColision.push_back(new Rectangle(1613, 350, 115, 140));
		//rectangulosColision.push_back(new Rectangle(1613, 350, 115, 140));
		rectangulosColision.push_back(new Rectangle(0, 1080, 1920, 1081));
		rectangulosColision.push_back(new Rectangle(1920, 0, 1920, 1080));
		rectangulosColision.push_back(new Rectangle(0, 0, 1920, 0));
		basuras.push_back(new Basura(720, 860));
		basuras.push_back(new Basura(1525, 850));//LISTO
		basuras.push_back(new Basura(1400, 10));//LISTO
		basuras.push_back(new Basura(750, 250));//LISTO
	}
	~Escenario2() {	}
	//get y set
	bool getterminarnivel() { return terminarnivel; }
	bool getmorirjugador() { return morirjugador; }
	bool getbasuraagregada() { return basuraagregada; }
	bool getdesaparecerlobos() { return desaparecerlobos; }
	bool getmorirlobos() { return morirlobos; }
	void setterminarnivel(bool terminarnivel) { this->terminarnivel = terminarnivel; }
	void setmorirjugador(bool morirjugador) { this->morirjugador = morirjugador; }
	void setbasuraagregada(bool basuraagregada) { this->basuraagregada = basuraagregada; }
	void setdesaparecerlobos(bool desaparecerlobos) { this->desaparecerlobos = desaparecerlobos; }
	void setmorirlobos(bool morirlobos) { this->morirlobos = morirlobos; }
	int getContadorBasuras() { return ge->getContadorBasuras(); }
	void setContadorBasuras(int a) { this->ge->setContadorBasuras(a); }
	bool getreiniciarbasuras() { return reiniciarbasuras; }
	void setreiniciarbasuras(bool reiniciarbasuras) { this->reiniciarbasuras = reiniciarbasuras; }
	Rectangle getRectangleAliadoXY() {
		Rectangle r = aliado->getRectangle();
		return r;
	}
	void setRectangleAliado(Rectangle r) { this->aliado->setRectangle(r); }
	//Cambia la posicion del aliado
	void setXYAliado(int x, int y) { this->aliado->setX(x); this->aliado->setY(y); }
	//Metodos
	void moverTodo(BufferedGraphics^ buffer, Bitmap^ bl, Bitmap^ be, Bitmap^ bb, Bitmap^ bm, Bitmap^ bf, Personaje* jugador) {
		for (int i = 0; i < basuras.size(); i++) {
			basuras.at(i)->mover(buffer, bb);

		}
		//Las basuras
		if (ge->getContadorBasuras() == 4 && !basuraagregada)
		{
			basuras.push_back(new Basura(1850, 500));
			basuraagregada = true;
		}
		//Movimiento de los lobos
		if (lobo->getDesaparecer()) {
			lobo->moverHorizontal(buffer, be);
		}
		if (lobo1->getDesaparecer()) {
			lobo1->moverHorizontal(buffer, be);
		}
		if (lobo2->getDesaparecer()) {
			lobo2->moverVertical(buffer, be);
		}
		if (ge->getContadorBasuras() == 4)
		{
			elefanteAparece(buffer, bf);
		}
		if (ge->getContadorBasuras() == 5)
		{
			terminarnivel = true;
		}
		if (ge->getContadorBasuras() == 3)
		{
			aliado->mover(buffer, bl, 2);
		}
		if (jugador->getvidaunica() == true) {
			morirjugador = true;
		}
	}
	void rectangulosLimites(BufferedGraphics^ buffer) {
		for (int i = 0; i < rectangulosColision.size(); i++)
		{
			buffer->Graphics->DrawRectangle(gcnew Pen(Color::Red), *(rectangulosColision.at(i)));
		}
	}
	void iniciar(BufferedGraphics^ buffer, Bitmap^ bl, Bitmap^ be, Bitmap^ bb, Bitmap^ bm, Bitmap^ bf, Personaje* jugador) {
		// Creamos los graficos del formulario
		if (terminarnivel == false)
		{
			moverTodo(buffer, bl, be, bb, bm, bf, jugador);
			//rectangulosLimites(buffer);
			interacciónPersonajeLimites(jugador, buffer);
			lobo->colisionPersonaje(jugador, lobo);
			lobo1->colisionPersonaje(jugador, lobo1);
			lobo2->colisionPersonaje(jugador, lobo2);
			elf->colisionPersonaje(jugador, elf);
			ge->colisionPersonajeBasura(jugador, basuras);
			if (morirlobos == true)
			{
				ge->limpiarArreglo();
			}
			if (reiniciarbasuras == true)
			{
				newVectorBasuras();
				reiniciarbasuras = false;
			}
		}
	}

	void interacciónPersonajeLimites(Personaje* jugador, BufferedGraphics^ bg) {
		Rectangle r2 = Rectangle(jugador->getX() + jugador->getdx() + 40, jugador->getY() + jugador->getdy() + 80, 30, 28);
		//bg->Graphics->DrawRectangle(gcnew Pen(Color::Blue), r2);
		for (int i = 0; i < rectangulosColision.size(); i++)
		{
			if ((rectangulosColision.at(i)->IntersectsWith(r2))) {
				jugador->setdx(0); jugador->setdy(0);
			}
			else {

			}

		}
	}
	void eliminarVector() {
		basuras.clear();
	}

	int elefanteAparece(BufferedGraphics^ buffer, Bitmap^ bf) {
		int a = 0;
		if (ge->getContadorBasuras() == 4)
		{
			elf->moverVertical(buffer, bf);
			a = 1;
		}
		return a;
	}

	void desaparecerLobos(){
		lobo->setDesaparecer(false);
		lobo1->setDesaparecer(false);
		lobo2->setDesaparecer(false);
		Rectangle r = Rectangle(0, 0, 10, 10);
		lobo->setR(r);
		lobo1->setR(r);
		lobo2->setR(r);
		desaparecerlobos = true;
	}

	bool aliadoPosicion() {
		bool f = false;
		if (aliado->getX() == 1080 && aliado->getY() == 431 && morirlobos == false)
		{

			f = true;
		}
		return f;
	}
	void newVectorBasuras() {
		Archivo* a = new Archivo();
		vector<int> v_posicionesB;
		v_posicionesB = a->leerPosicionBasuras();
		basuras.push_back(new Basura(v_posicionesB[0], v_posicionesB[1]));
		basuras.push_back(new Basura(v_posicionesB[2], v_posicionesB[3]));
		basuras.push_back(new Basura(v_posicionesB[4], v_posicionesB[5]));
		basuras.push_back(new Basura(v_posicionesB[6], v_posicionesB[7]));
	}
	void reiniciarAliado(BufferedGraphics^ buffer, Bitmap^ bl) {
		Archivo* a = new Archivo();
		vector<int> v_aliado;
		vector<bool> v_aliadoB;
		v_aliado = a->leerPosicionInicial();
		v_aliadoB = a->leerBoleanos();
		aliado->setX(v_aliado[2]);
		aliado->setY(v_aliado[3]);
		aliado->setcontadormovimiento(v_aliado[6]);
		aliado->setcontadorMovimiento2(v_aliado[7]);
		aliado->setmoveraliado(v_aliadoB[23]);
		if (ge->getContadorBasuras() == 3)
		{
			aliado->mover(buffer, bl, 2);
		}
	}	
	void reiniciarlobos() {
		Archivo* a = new Archivo();
		vector<bool> v_posicionesB;
		v_posicionesB = a->leerBoleanos();
		lobo->setDesaparecer(v_posicionesB[19]);
		lobo1->setDesaparecer(v_posicionesB[20]);
		lobo2->setDesaparecer(v_posicionesB[21]);
		desaparecerlobos = v_posicionesB[22];
	}
};