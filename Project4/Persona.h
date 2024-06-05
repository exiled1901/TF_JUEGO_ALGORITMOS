#pragma once
using namespace System::Drawing;

enum Direcciones { Ninguna, Abajo, Arriba, Izquierda, Derecha };

class Persona {
protected:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	Direcciones ultimaTecla;
	Direcciones direccion;
	Rectangle r;
public:
	Persona(int x, int y, int ancho, int alto, int dx, int dy) {
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
		this->dx = dx;
		this->dy = dy;
		this->indiceX = 0;
		this->indiceY = 0;
		ultimaTecla = Arriba;
		direccion = Ninguna;
	}
	~Persona() {}

	void setDireccion(Direcciones d) {
		direccion = d;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}
	void setdx(int dx) {
		this->dx = dx;
	}
	void setdy(int dy) {
		this->dy = dy;
	}
	void setAncho(int ancho) {
		this->ancho = ancho;
	}
	void setAlto(int alto) {
		this->alto = alto;
	}
	void setIndiceX(int indiceX) {
		this->indiceX = indiceX;
	}
	void setIndiceY(int indiceY) {
		this->indiceY = indiceY;
	}
	void setRectangle(Rectangle r) {
		this->r = r;
	}
	Rectangle getRectangle() {
		return this->r;
	}
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
	int getdx() {
		return this->dx;
	}
	int getdy() {
		return this->dy;
	}
	int getAlto() {
		return this->alto;
	}
	int getAncho() {
		return this->ancho;
	}
	int getIndiceX() {
		return this->indiceX;
	}
	int getIndiceY() {
		return this->indiceY;
	}
	virtual void mover(BufferedGraphics^ bg, Bitmap^ bm, int a) = 0;
	void dibujar(BufferedGraphics^ bg, Bitmap^ bm) {
		Rectangle area = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle zonaAumento = Rectangle(x, y, ancho, alto);
		bg->Graphics->DrawImage(bm, zonaAumento, area, GraphicsUnit::Pixel);
		//bg->Graphics->DrawRectangle(gcnew Pen(Color::Red), r);


	}
	void dibujar_nivel_1(BufferedGraphics^ bg, Bitmap^ bm) {
		Rectangle area = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle zonaAumento = Rectangle(x, y, ancho * 2, alto * 2);
		bg->Graphics->DrawImage(bm, zonaAumento, area, GraphicsUnit::Pixel);
		r = Rectangle(x + 80, y + 160, 30 * 2, 28 * 2);
		//bg->Graphics->DrawRectangle(gcnew Pen(Color::Red), r);

	}
	void dibujar_nivel_3(BufferedGraphics^ bg, Bitmap^ bm) {
		Rectangle area = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle zonaAumento = Rectangle(x, y, ancho * 3, alto * 3);
		bg->Graphics->DrawImage(bm, zonaAumento, area, GraphicsUnit::Pixel);
		//bg->Graphics->DrawRectangle(gcnew Pen(Color::Red), r);
	}
	void dibujar_nivel_secreto(BufferedGraphics^ bg, Bitmap^ bm) {
		Rectangle area = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle zonaAumento = Rectangle(x, y, ancho, alto);
		bg->Graphics->DrawImage(bm, zonaAumento, area, GraphicsUnit::Pixel);
		r = Rectangle(x + 20, y + 20, ancho - 40, alto - 40);
		//bg->Graphics->DrawRectangle(gcnew Pen(Color::Red), r);
	}

};
