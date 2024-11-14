#pragma once

#include <iostream> 

#include "Particle.h"
#include "ParticleSystem.h"


class Scene
{
private:

	std::vector<Particle*> sParticles; // Vector de particulas de la escena.
	std::vector<ParticleSystem*> sParticleSystems; // Vector de sistemas de particulas de la escena.

public:

	//------Constructoras y destructoras:

	// Constructora de Scene.
	Scene();
	// Destructora de scene.
	~Scene();


	//------Metodos de la escena.

	// Inicializacion de la escena.
	virtual void initScene();
	// Update de Scene.
	void update(float t);
	// Activa la escena.
	void activateScene();
	// Desactiva la escena.
	void deactivateScene();


	//------Metodos para meter cosas a la escena:

	// Mete una particula.
	void addParticle(Particle* par);
	// Mete un sitema de particulas.
	void addParticleSystem(ParticleSystem* parSys);
};