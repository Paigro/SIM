#pragma once

#include <PxPhysicsAPI.h>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Projectile.h"


class ForceGenerator
{
protected:

	float radius; // Radio en el que afecta el generador.
	Vector3 position; // Posicion del generador.

public:

	//------Constructoras y destructoras:

	// Constructora de ForceGenerator base.
	ForceGenerator(Vector3 pos, float rad = 0);
	// Desctructora de ForceGenerator virtual.
	virtual ~ForceGenerator() = 0;


	//------Setters:

	// Settea un nuevo radio.
	void setRadius(float newRad);


	//------Gestion de particulas:

	// Comprueba si la particula esta dentro de la zona que afecta.
	bool isOnRadius(Vector3 parPos);
	// Genera una fuerza dada una particula.
	virtual Vector3 generateForce(Particle& par) = 0;
	// Update de ForceGenerator virtual.
	virtual void updateFGen(float t) = 0;
};