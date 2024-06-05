#pragma once
#include "Barrera.h"
#include "Enemigos.h"
class Bala : public Enemigos {
private:
    // int contadorMovimiento;
    // int contadorMovimiento2;
    bool dibuja;

public:
    Bala(int _x, int _y);
    ~Bala();
    void moverHorizontal(BufferedGraphics^ bg, Bitmap^ bm);
    void moverVertical(BufferedGraphics^ bg, Bitmap^ bm);
    void setDibuja(bool dibuja);
    bool getDibuja();

    /*void colisionBarrera(Barrera* barrera, Bala* ba) {
        if (ba->getR().IntersectsWith(barrera->getR())) {

            barrera->setVidas(barrera->getVidas() - 1);
        }
    }*/
};

Bala::Bala(int _x, int _y) : Enemigos(_x, _y, 246, 246, 0, 0) {
    x = _x;
    y = _y;
    dibuja = true;
    //contadorMovimiento = 0;
    //contadorMovimiento2 = 0;
}

Bala::~Bala() {}

void Bala::moverHorizontal(BufferedGraphics^ bg, Bitmap^ ba) {
    if (dibuja == true) {
        indiceY = 0;
        if (indiceX < 3) {
            indiceX++;
        }
        else {
            indiceX = 0;
        }
        dx = -30;
        dy = 0;

    }
    Rectangle h = Rectangle(x + 110, y + 145, 82, 82);
    setR(h);
    if (x < 1600) {
        dibujar(bg, ba);
    }
    x += dx;
    y += dy;
}

void Bala::setDibuja(bool dibuja) {
    this->dibuja = dibuja;
}
bool Bala::getDibuja() {
    return dibuja;
}

void Bala::moverVertical(BufferedGraphics^ bg, Bitmap^ bf) {}
