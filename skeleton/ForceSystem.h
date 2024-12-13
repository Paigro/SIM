#pragma once

#include <PxPhysicsAPI.h>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "ForceGenerator.h"
#include "Particle.h"
#include "DinamicRigidBody.h"


class ForceSystem
{
private:

	std::vector <ForceGenerator*> vFGenerators; // Vector de generadores de fuerzas.

	bool isActive = true;

public:

	//------Constructoras y destructoras:

	// Constructora de ForceSystem base.
	ForceSystem();
	// Destructora de ForceSystem.
	~ForceSystem();


	//------Gestion de los generadores:

	// Mete un generador de fuerzas al vector de generadores de fuerzas.
	void addForceGenerator(ForceGenerator* fGen);
	// Update de ForceSystem.
	void update(float t);
	// Para activarlo o desactivarlo.
	void setActive(bool act);


	//------Gestion de las particulas:

	// Mete a las particulas las fuerzas correspondientes.
	void addForceToParticles(std::vector<Particle*> vPar, float t);
	// Mete a los rigigBodies las fuerzas correspondientes.
	void addForceToRigidBodies(std::vector<DinamicRigidBody*> vRB, float t);
};