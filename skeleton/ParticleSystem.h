#pragma once

#include <vector>

#include "Particle.h"
#include "ParticleGenerator.h"
#include "FountainGenerator.h"
#include "SmokeGenerator.h"
#include "FireworkGenerator.h"
#include "RandomGenerator.h"


class ParticleSystem
{
private:

	std::vector<Particle*> vParticles; // Vector de particulas del sistema de particulas.
	std::vector<Particle*> particlesGenerated; // Vector de particulas del generador de particulas.

	int maxParticles; // Maximo de particulas.

	Vector3 initPos; //  Posicion inicial.
	Vector3 initVel; //  Velocidad inicial.

	float timeToLive; // Tiempo que va a vivir el sistema.
	float timeAlive; // Tiempo que lleva vivo.

	ParticleGenerator* generator = nullptr; // Referencia al generador de particulas.

	char type; // Tipo de sistema de particulas.

	bool dieByTime; // Si puede morir por tiempo o es infinito.
	bool isActive = true;

public:

	//------Constructoras y destructoras:

	// Constructora de ParticleSystem.
	ParticleSystem(Vector3 pos, Vector3 vel, int maxPar, float tim, char typ, Vector4 parColor = { 1.0, 1.0, 1.0, 1.0 });
	// Destructora de ParticleSystem.
	~ParticleSystem();


	//------Metodos de ParticleSystem:

	// Update de ParticleSystem.
	bool update(float t);
	//
	void setActive(bool act);


	//------Getters y setters:

	// Gettea el vector de particulas.
	std::vector<Particle*> getVParticles() { return vParticles; }
};