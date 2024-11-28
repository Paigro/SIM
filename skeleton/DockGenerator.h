#pragma once

#include "ParticleGenerator.h"
#include "AnchorForceGenerator.h"


class DockGenerator : public ParticleGenerator
{
private:

	float minTimeToLive; // Tiempo minimo que va a vivir cada particula.
	float maxTimeToLive; // Tiempo maximo que va a vivir cada particula.

public:

	//------Constructoras y destructoras:

	// Constructora de DockGenerator.
	DockGenerator(Vector3 ori, Vector3 vel, int nPar, float minT, float maxT);
	// Destructora de DockGenerator.
	~DockGenerator();


	//------Metodos heredados:

	// Genera particulas con la diferencia entra las particulas activas y el maximo, las mete a un vector y lo devuelve.
	std::vector<Projectile*> CreateParticles(int actP, int maxP) override;
	// Genera particulas con la diferencia entra las particulas activas y el maximo, las mete a un vector y lo devuelve.
	std::vector<Particle*> CreateParticles() override;
};