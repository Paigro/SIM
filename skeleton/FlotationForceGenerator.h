#pragma once

#include "ForceGenerator.h"


class FlotationForceGenerator : public ForceGenerator
{
private:

	float density; // Densidad del liquido.
	float height; // Donde esta el nivel del liquido.

public:

	//------Constructoras y destructoras:

	// Constructora de FlotationForceGenerator.
	FlotationForceGenerator(float den, float hei);
	// Destructora de FlotationForceGenerator.
	~FlotationForceGenerator();


	//------Metodos heredados:

	// Genera la fuerza.
	Vector3 generateForce(Vector3 objPos, Vector3 objVel, float objSize) override;
	//
	void updateFGen(float t) override {}
	//
	bool isOnRadius(Vector3 pos) override;

};