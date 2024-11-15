#pragma once

#include "ForceGenerator.h"


class WindForceGenerator : public ForceGenerator
{
private:

	Vector3 windVel; // Velocidad del viento.
	float k1 = 10; // Coeficiente de rozamiento del viendo.
	Vector3 k2 = { 0, 0, 0 }; //

public:

	//------Constructoras y destructoras:

	// Constructora de WindForceGenerator base.
	WindForceGenerator(Vector3 pos, float rad, Vector3 vel);
	// Desctructora de WindForceGenerator.
	~WindForceGenerator() {};


	//------Metodos heredados:

	// Update de WindForceGenerator.
	void update(float t) {};
	// Genera la fuerza del viento.
	Vector3 generateForce(Particle& par) override;
};