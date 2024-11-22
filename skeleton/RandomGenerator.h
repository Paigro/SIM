#pragma once

#include "ParticleGenerator.h"


class RandomGenerator : public ParticleGenerator
{
private:

	float minTimeToLive; // Tiempo minimo que va a vivir cada particula.
	float maxTimeToLive; // Tiempo maximo que va a vivir cada particula.

	float minPos; // Posicion minimo.
	float maxPos; // Posicion maxima.

public:

	//------Constructoras y destructoras:

	// Constructora de RandomGenerator.
	RandomGenerator(Vector3 ori, Vector3 vel, int nPar, float minT, float maxT,float minP, float maxP);
	// Destructora de RandomGenerator.
	~RandomGenerator();


	//------Metodos heredados:

	// Genera particulas con la diferencia entra las particulas activas y el maximo, las mete a un vector y lo devuelve.
	std::vector<Projectile*> CreateParticles(int actP, int maxP) override;
};