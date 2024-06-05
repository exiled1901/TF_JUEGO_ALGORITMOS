#pragma once
using namespace System::Drawing;

enum DireccionesE { NingunaE, AbajoE, ArribaE, IzquierdaE, DerechaE };

class Enemigos {
protected:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	DireccionesE ultimaTecla;
	DireccionesE direccion;
	Rectangle r1;
public:
	Enemigos() {}
	Enemigos(int x, int y, int ancho, int alto, int dx, int dy);
	~Enemigos();

	void setDireccion(DireccionesE d);
	virtual void moverHorizontal(BufferedGraphics^ bg, Bitmap^ bm) = 0;
	virtual void moverVertical(BufferedGraphics^ bg, Bitmap^ bm) = 0;
	void dibujar(BufferedGraphics^ bg, Bitmap^ bm);

	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	Rectangle getR() {
		return r1;
	}
	void setR(Rectangle r) { this->r1 = r; }

	void setXY(int x, int y) { this->x = x; this->y = y; }

};
Enemigos::Enemigos(int x, int y, int ancho, int alto, int dx, int dy) {
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->alto = alto;
	this->dx = dx;
	this->dy = dy;
	this->indiceX = 0;
	this->indiceY = 0;
	ultimaTecla = ArribaE;
	direccion = NingunaE;
	r1 = Rectangle(x, y, ancho, alto);
}
Enemigos::~Enemigos() {}

void Enemigos::setDireccion(DireccionesE d) {
	direccion = d;
}
void Enemigos::dibujar(BufferedGraphics^ bg, Bitmap^ bm) {
	Rectangle area = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
	Rectangle zonaAumento = Rectangle(x, y, ancho * 1.5, alto * 1.5);
	bg->Graphics->DrawImage(bm, zonaAumento, area, GraphicsUnit::Pixel);
	//r1 = Rectangle(x, y+((alto*1.5)/4), ancho*1.5,(( alto*1.5)/2));
	//r2 = Rectangle(x, y, ancho*1.5, alto*1.5);
	//bg->Graphics->DrawRectangle(gcnew Pen(Color::Red), r1);
	x += dx;
	y += dy;
}