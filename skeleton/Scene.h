#pragma once

#include <iostream> 

#include "Particle.h"
#include "ParticleSystem.h"
#include "ForceSystem.h"


class Scene
{
private:

	std::vector<Particle*> vParticles; // Vector de particulas de la escena.
	std::vector<ParticleSystem*> vParticleSystems; // Vector de sistemas de particulas de la escena.
	std::vector<ForceSystem*> vForceSystems; // Vector de sistemas de fuerzas de la escena.

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
	void updateScene(float t);
	// Activa la escena.
	void activateScene();
	// Desactiva la escena.
	void deactivateScene();


	//------Metodos para meter cosas a la escena:

	// Mete una particula.
	void addParticle(Particle* par);
	// Mete un sitema de particulas.
	void addParticleSystem(ParticleSystem* parSys);
	// Mete un sistema de fuerzas.
	void addForceSistem(ForceSystem* forSys);
};