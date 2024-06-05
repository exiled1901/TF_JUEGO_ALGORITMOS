#pragma once
using namespace System::Drawing;

class Objetos {
protected:
	int x;
	int y;
	int ancho;
	int alto;
	int indiceX;
	int indiceY;
	Rectangle r;
public:
	Objetos(int x, int y, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
		this->indiceX = 0;
		this->indiceY = 0;
		r = Rectangle(x, y, ancho, alto);
	}
	~Objetos() {}
	Rectangle getR() { return this->r; }
	void setR(Rectangle r) { this->r = r; }
	virtual void mover(BufferedGraphics^ bg, Bitmap^ bm) = 0;
	virtual void dibujar(BufferedGraphics^ bg, Bitmap^ bm) {
		Rectangle area = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle zonaAumento = Rectangle(x, y, ancho * 1.5, alto * 1.5);
		bg->Graphics->DrawImage(bm, zonaAumento, area, GraphicsUnit::Pixel);
		//bg->Graphics->DrawRectangle(gcnew Pen(Color::Pink), r);
	}
};
