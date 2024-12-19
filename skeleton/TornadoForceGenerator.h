#pragma once

#include "ForceGenerator.h"


class TornadoForceGenerator : public ForceGenerator
{
private:

	float k; // Coeficiente de rozamiento del torbellino.
	float attraction;

	Vector3 tornadoAxis; // Eje en el que esta el tornado: XY, YZ o XZ.

	int innerRadius; // Radio interior al que giraran los objetos. Dentro de el no se genera fuerza.

	bool isActive = true; // Si esta activa la fuerza o no.

public:

	//------Constructoras y destructoras:

	// Constructora de TornadoForceGenerator base con posicion inicial y radio.
	TornadoForceGenerator(Vector3 pos, float rad, float _k = 1, Vector3 axis = Vector3(0, 0, 1), float inRadius = 20, float attractionCte = 0);
	// Desctructora de TornadoForceGenerator.
	~TornadoForceGenerator() {};


	//------Metodos heredados:

	// Update de TornadoForceGenerator.
	void updateFGen(float t) {};
	// Genera la fuerza del viento.
	Vector3 generateForce(Vector3 objPos, Vector3 objVel, float objSize) override;


	//------Activacion/desactivacion:

	// Settea si genera la fuerza o no.
	void setActive(bool act);
};