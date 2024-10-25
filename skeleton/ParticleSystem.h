#pragma once

#include <vector>

#include "Projectile.h"
#include "ParticleGenerator.h"
#include "FountainGenerator.h"
#include "SmokeGenerator.h"
#include "FireworkGenerator.h"


class ParticleSystem
{
private:

	std::vector<Projectile*> vParticles; // Vector de particulas del sistema de particulas.
	std::vector<Projectile*> particlesGenerated; // Vector de particulas del generador de particulas.

	int maxParticles; // MAximo de particulas
	Vector3 initPos; // 
	Vector3 initVel; // 

	float timeToLive; // 
	float timeAlive; // 

	ParticleGenerator* generator = nullptr;

	char type; // Tipo de sistema de particulas.

public:

	//------Constructoras y destructoras:

	// Constructora de ParticleSystem.
	ParticleSystem(Vector3 pos, Vector3 vel, int maxPar, float tim, char typ);
	// Destructora de ParticleSystem.
	~ParticleSystem();


	//------Metodos de ParticleSystem:

	// Update de ParticleSystem.
	bool update(float t);
};