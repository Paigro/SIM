#pragma once

#include <vector>
#include <random>

#include "Particle.h"


class ParticleGenerator
{
private:

protected:

	Vector3 initPos; // Posicion inicial de las particulas.
	Vector3 medVel; // Velocidad media de las particulas.

	std::vector<Particle*> vParticles; // Vector de proyectiles del generador de particulas..

	int nParticles; // Numero de particulas.

	std::default_random_engine randomGenerator; // Generador de randoms del generador de particulas.

	Particle* orParticle = nullptr; // Particula de origen de donde saldran el resto.

public:

	//------Constructoras y destructoras:

	// Constructora de ParticleGenerator.
	ParticleGenerator(Vector3 iPos, Vector3 mVel, int nPar);
	// Destructora de ParticleGenerator.
	~ParticleGenerator();


	//------Metodos virtuales:

	// Genera particulas con la diferencia entra las particulas activas y el maximo, las mete a un vector y lo devuelve.
	virtual std::vector<Particle*> CreateParticles(int actP, int maxP) = 0;
	// Genera partculas y las devuelve en un vector.
	virtual std::vector<Particle*> CreateParticles() = 0;


	//------Metodos de ParticleGenerator.

	// Para activar o desactivar el punto de origen (para que no se vea o si).
	void setActive(bool act);
};