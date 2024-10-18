#pragma once

#include <vector>

#include "Particle.h"

constexpr int MAX_PARTICLES = 200;

class ParticleSystem
{
private:

	Particle* particleRef = nullptr; // Particula referencia para que sean todas iguales.
	std::vector<Particle*> vParticles; // Vector de particulas del sistema de particulos.

	int nParticles; // Particulas que genera en cada iteracion.
	Vector3 initPos; // Posicion inicial del sistema.
	Vector3 initVel; // Velocidad inicial de las particulas.

	float timeToAppear; // Tiempo que tiene que pasar para que aparezca una particula.
	float timerToAppear; // Contador para que aparezca una particula.

public:

	//------Constructoras y destructoras:

	// Constructora de ParticleSystem.
	ParticleSystem(Particle* pRef, Vector3 iPos, Vector3 iVel, int nPar);
	// Constructora de ParticleSystem.
	~ParticleSystem();


	//------Metodos de ParticleSystem:

	// Update de Particlesystem.
	void update(float t);


	//------Metodos del sistema de particulas:

	// Genera particulas.
	void generateParticles(Vector3 _pos);
};