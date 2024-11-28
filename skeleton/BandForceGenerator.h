#pragma once

#include "ForceGenerator.h"


class BandForceGenerator : public ForceGenerator
{
private:

	Particle* part1 = nullptr; // Particula n1.
	Particle* part2 = nullptr; // Particula n2, la que esta atachada a la 1.

	double k; // Coeficiente de elasticidad.
	double restingLength; // Longitud en reposo.

public:

	//------Constructoras y destructoras:

	// Constructora de BandForceGenerator.
	BandForceGenerator(Vector3 pos,float rad, float _K, float rest, Particle* p1, Particle* p2 = nullptr);
	// Destructora de BandForceGenerator.
	~BandForceGenerator();


	//------Metodos heredados:

	// Genera la fuerza.
	Vector3 generateForce(Particle& par) override;
	//
	void updateFGen(float t) override {}
	//
	bool isOnRadius(Particle* part);
};