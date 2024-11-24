#pragma once

#include <PxPhysicsAPI.h>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "ForceGenerator.h"
#include "Projectile.h"


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

	// Mete un generador de fuerzas al vector.
	void addForceGenerator(ForceGenerator* fGen);
	// Update de ForceSystem.
	void update(float t);
	//
	void setActive(bool act);


	//------Gestion de las particulas:

	//
	void addForceToParticles(std::vector<Projectile*> vPar, float t);
};