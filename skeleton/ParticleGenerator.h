#pragma once

#include "Projectile.h"

#include <vector>

class ParticleGenerator
{
private:



protected:
	
	Vector3 initPos; // Posicion inicial.
	Vector3 medVel; // Velocidad media de las particulas.

	std::vector<Projectile*> vProjectiles; // Vector de proyectiles del generador.

	int nParticles; // Numero de particulas.

public:

	//------Constructoras y destructoras:

	// Constructora de ParticleGenerator.
	ParticleGenerator();
	// Destructora de ParticleGenerator.
	~ParticleGenerator();
};