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
	// KeyPressed virtual de Scene.
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera) {};


	//------Metodos para meter cosas a la escena:

	// Mete una particula al vector de particulas de la escena.
	void addParticle(Particle* par);
	// Mete un sitema de particulas al vector de sistemas de particulas de la escena.
	void addParticleSystem(ParticleSystem* parSys);
	// Mete un sistema de fuerzas al vector de sistemas de fuerzas de la escena.
	void addForceSistem(ForceSystem* forSys);
};