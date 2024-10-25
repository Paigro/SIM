#pragma once

#include <vector>
#include <random>

#include "Projectile.h"


class ParticleGenerator
{
private:



protected:

	Vector3 initPos; // Posicion inicial de las particulas.
	Vector3 medVel; // Velocidad media de las particulas.

	std::vector<Projectile*> vProjectiles; // Vector de proyectiles del generador de particulas..

	int nParticles; // Numero de particulas.

	std::default_random_engine randomGenerator; // Generador de randoms del generador de particulas..

	Particle* orParticle = nullptr; // Particula de origen de donde saldran el resto.

public:

	//------Constructoras y destructoras:

	// Constructora de ParticleGenerator.
	ParticleGenerator(Vector3 iPos, Vector3 mVel, int nPar);
	// Destructora de ParticleGenerator.
	~ParticleGenerator();


	//------Metodos virtuales:

	// Genera particulas con la diferencia entra las particulas activas y el maximo, las mete a un vector y lo devuelve.
	virtual std::vector<Projectile*> CreateParticles(int actP, int maxP) = 0;
};