#pragma once

#include "ParticleGenerator.h"


class SmokeGenerator : public ParticleGenerator
{
private:

	float minTimeToLive; // Tiempo minimo que va a vivir cada particula.
	float maxTimeToLive; // Tiempo maximo que va a vivir cada particula.

public:

	//------Constructoras y destructoras:

	// Constructora de SmokeGenerator.
	SmokeGenerator(Vector3 ori, Vector3 vel, int nPar, float minT, float maxT);
	// Destructora de SmokeGenerator.
	~SmokeGenerator();


	//------Metodos heredados:

	// Genera particulas con la diferencia entra las particulas activas y el maximo, las mete a un vector y lo devuelve.
	std::vector<Particle*> CreateParticles(int actP, int maxP) override;
	std::vector<Particle*> CreateParticles() override { return std::vector<Particle*>(); };
};