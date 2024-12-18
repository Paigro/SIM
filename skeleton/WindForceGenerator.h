#pragma once

#include "ForceGenerator.h"


class WindForceGenerator : public ForceGenerator
{
private:

	Vector3 windVel; // Velocidad del viento.
	Vector3 k2 = { 0, 0, 0 };

	float k1 = 10; // Coeficiente de rozamiento del viendo.

	bool isActive = true;

public:

	//------Constructoras y destructoras:

	// Constructora de WindForceGenerator base con posicion inicial, radio y velocidad del viento.
	WindForceGenerator(Vector3 pos, float rad, Vector3 vel, float _k1 = 10, Vector3 _k2 = { 0, 0, 0 });
	// Desctructora de WindForceGenerator.
	~WindForceGenerator() {};


	//------Metodos heredados:

	// Update de WindForceGenerator.
	void updateFGen(float t) {};
	// Genera la fuerza del viento.
	Vector3 generateForce(Vector3 objPos, Vector3 objVel, float objSize) override;


	// Metodos para el viento:

	//
	void setActive(bool act);
};