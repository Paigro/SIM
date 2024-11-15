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

	int maxParticles; // Maximo de particulas.
	Vector3 initPos; //  Posicion inicial.
	Vector3 initVel; //  Velocidad inicial.

	float timeToLive; // Tiempo que va a vivir el sistema.
	float timeAlive; // Tiempo que lleva vivo.

	ParticleGenerator* generator = nullptr; // Referencia al generador de particulas.

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


	//------Getters y setters:

	// Gettea el vector de particulas.
	std::vector<Projectile*> getVParticles() { return vParticles; }
};