#pragma once
#include <fstream>
#include <conio.h>
#include <iostream>
#include <vector>
#include <string>
#include "Personaje.h"
using namespace std;

class Archivo {
	fstream archivo;
public:
	Archivo() {

	}
	~Archivo() {

	}
	bool convertirABool(const string& str) {
		if (str == "true") {
			return true;
		}
		else if (str == "false") {
			return false;
		}
		else {
			// Manejar algún error si es necesario
			throw runtime_error("Valor booleano no reconocido: " + str);
		}
	}
	vector<int>leerPosicionInicial() {
		int posicion;
		vector<int>v_posicion;
		archivo.open("PosicionInicial.txt", ios::in);
		if (archivo.is_open())
		{
			while (archivo >> posicion)
			{
				v_posicion.push_back(posicion);
			}
		}
		archivo.close();
		return v_posicion;
	}
	vector<bool>leerBoleanos() {
		int posicion;
		string valor;
		vector<bool>v_posicionB;
		archivo.open("PosicionBooleanos.txt", ios::in);
		if (archivo.is_open())
		{
			while (archivo >> valor)
			{
				bool valor_bool = convertirABool(valor);
				v_posicionB.push_back(valor_bool);
			}
		}
		archivo.close();
		return v_posicionB;
	}
	vector<int>leerIndices() {
		int posicion;
		vector<int>v_posicionI;
		archivo.open("PosicionIndices.txt", ios::in);
		if (archivo.is_open())
		{
			while (archivo >> posicion)
			{
				v_posicionI.push_back(posicion);
			}
		}
		archivo.close();
		return v_posicionI;
	}
	vector<int>leerPosicionBasuras() {
		int posicion;
		vector<int>v_posicionB;
		archivo.open("vectorBasuras.txt", ios::in);
		if (archivo.is_open())
		{
			while (archivo >> posicion)
			{
				v_posicionB.push_back(posicion);
			}
		}
		archivo.close();
		return v_posicionB;
	}
	vector<int>leerPosicionBalas() {
		int posicion;
		vector<int>v_posicionBl;
		archivo.open("vectorBalas.txt", ios::in);
		if (archivo.is_open())
		{
			while (archivo >> posicion) {
				v_posicionBl.push_back(posicion);
			}
		}
		archivo.close();
		return v_posicionBl;
	}
	/*void guardarPosiciones(Personaje* jugador) {
		archivo.open("GuardarPartidaPosiciones.txt", ios::out);
		if (archivo.is_open())
		{
			archivo << jugador->getX() << endl;
			archivo << jugador->getY() << endl;
			archivo << jugador->getAncho() << endl;
			archivo << jugador->getAlto() << endl;
			archivo << jugador->getIndiceX() << endl;
			archivo << jugador->getIndiceY() << endl;
			archivo.close();
		}
	}
	vector<int>leerPosicionFinal() {
		int posicion;
		vector<int>v_posicion;
		archivo.open("GuardarPartidaPosiciones.txt", ios::in);
		if (archivo.is_open())
		{
			while (archivo>>posicion)
			{
				v_posicion.push_back(posicion);
			}
		}
		archivo.close();
		return v_posicion;
	}*/
	/*void guardarBooleanos(bool escenarioOne, bool escenarioTwo, bool escenarioTree) {
		archivo.open("GuardarPartidaBooleanos.txt", ios::out);
		if (archivo.is_open())
		{
			archivo << escenarioOne << endl;
			archivo << escenarioTwo << endl;
			archivo << escenarioTree << endl;
			archivo.close();
		}
	}*/
	/*vector<bool>leerBoleanosFinales() {
		string valor;
		vector<bool>v_posicionBF;
		archivo.open("GuardarPartidaBooleanos.txt", ios::in);
		if (archivo.is_open())
		{
			while (archivo >> valor)
			{
				bool valor_bool = convertirABool(valor);
				v_posicionBF.push_back(valor_bool);
			}
		}
		archivo.close();
		return v_posicionBF;
	}*/
};
