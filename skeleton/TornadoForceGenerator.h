#pragma once

#include "ForceGenerator.h"


class TornadoForceGenerator : public ForceGenerator
{
private:

	float k = 1; // Coeficiente de rozamiento del torbellino.

public:

	//------Constructoras y destructoras:

	// Constructora de TornadoForceGenerator base con posicion inicial y radio.
	TornadoForceGenerator(Vector3 pos, float rad, float _k = 1);
	// Desctructora de TornadoForceGenerator.
	~TornadoForceGenerator() {};


	//------Metodos heredados:

	// Update de TornadoForceGenerator.
	void updateFGen(float t) {};
	// Genera la fuerza del viento.
	Vector3 generateForce(Particle& par) override;
};
