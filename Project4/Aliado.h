#pragma once
#include "Persona.h"

class Aliado : public Persona {
private:
    int contadorMovimiento;
    int contadorMovimiento2;
    bool moveraliado;
public:
    Aliado(int _x, int _y) :Persona(_x, _y, 64, 104, 0, 0) {
        x = _x;
        y = _y;
        contadorMovimiento = 0;
        contadorMovimiento2 = 0;
        moveraliado = false;
    }
    ~Aliado() {}
    void setcontadormovimiento(int contadorMovimiento) { this->contadorMovimiento = contadorMovimiento; }
    int getcontadormovimiento() { return contadorMovimiento; }
    int getcontadormovimiento2() { return contadorMovimiento2; }
    void setcontadorMovimiento2(int contadorMovimiento2) { this->contadorMovimiento2 = contadorMovimiento2; }
    void setmoveraliado(bool moveraliado) { this->moveraliado = moveraliado; }
    void mover(BufferedGraphics^ bg, Bitmap^ bm, int a) {
        if (moveraliado == false)
        {
            if (contadorMovimiento < 43)
            {
                indiceY = 0;
                if (indiceX < 3)
                {
                    indiceX++;
                }
                else
                {
                    indiceX = 0;
                    contadorMovimiento2 = 0;
                }
                dx = 0;
                dy = 10;
                contadorMovimiento++;
            }
            else
            {
                if (contadorMovimiento2 < 22)
                {
                    indiceY = 1;
                    if (indiceX < 3)
                    {
                        indiceX++;
                    }
                    else
                    {
                        indiceX = 0;

                    }
                    contadorMovimiento2++;
                }
                dx = -10;
                dy = 0;
                if (contadorMovimiento2 == 22) {
                    contadorMovimiento = 0;
                    moveraliado = true;
                }
            }
        }
        else
        {
            dx = 0;
            dy = 0;
            indiceX = 0;
            indiceY = 0;
        }
        x += dx;
        y += dy;
        r = Rectangle(x + 10, y + 70, 30, 28);
        dibujar(bg, bm);
    }
};
