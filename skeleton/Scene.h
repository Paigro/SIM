#pragma once

#include <iostream> 

#include "Particle.h"
#include "ParticleSystem.h"
#include "ForceSystem.h"
#include "StaticRigidBody.h"
#include "DinamicRigidBody.h"


class Scene
{
private:

	std::vector<Particle*> vParticles; // Vector de particulas de la escena.
	std::vector<ParticleSystem*> vParticleSystems; // Vector de sistemas de particulas de la escena.
	std::vector<ForceSystem*> vForceSystems; // Vector de sistemas de fuerzas de la escena.
	std::vector<BaseRigidBody*> vRigidBodies; // Vector de rigid bodies de la escena.

protected:

	PxPhysics* gPhysics = nullptr; // Referencia a la fisica.
	PxScene* gScene = nullptr; // Referencia a la escena fisica.

public:

	//------Constructoras y destructoras:

	// Constructora de Scene.
	Scene(PxPhysics* physics, PxScene* scene);
	// Destructora de scene.
	~Scene();


	//------Metodos de la escena.

	// Inicializacion de la escena.
	virtual void initScene();
	// Update de Scene.
	virtual void updateScene(float t);
	// Activa la escena de Scene.
	virtual void activateScene();
	// Desactiva la escena de Scene.
	virtual void deactivateScene();
	// KeyPressed virtual de Scene.
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera) = 0;


	//------Metodos para meter cosas a la escena:

	// Mete una particula al vector de particulas de la escena.
	void addParticle(Particle* par);
	// Mete un sitema de particulas al vector de sistemas de particulas de la escena.
	void addParticleSystem(ParticleSystem* parSys);
	// Mete un sistema de fuerzas al vector de sistemas de fuerzas de la escena.
	void addForceSistem(ForceSystem* forSys);
	// Mete un rigid body al vector de rigid bodies de la escena.
	void addRigidBody(BaseRigidBody* rigBod);
};