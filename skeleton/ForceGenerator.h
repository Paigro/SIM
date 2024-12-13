#pragma once

#include <PxPhysicsAPI.h>

#include <iostream>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Particle.h"


class ForceGenerator
{
protected:

	float radius; // Radio en el que afecta el generador.
	Vector3 position; // Posicion del generador.

	RenderItem* renderItem = nullptr; // RenderItem de la esfera.

	// Genera la esfera que marca lo que afecta el sistema.
	void generateSphere();

public:

	//------Constructoras y destructoras:

	// Constructora de ForceGenerator base con posicion inicial y radio.
	ForceGenerator(Vector3 pos, float rad = 0);
	// Desctructora de ForceGenerator virtual.
	virtual ~ForceGenerator() = 0;


	//------Setters:

	// Settea un nuevo radio.
	void setRadius(float newRad);


	//------Gestion de particulas:

	// Comprueba si la particula esta dentro de la zona que afecta.
	virtual bool isOnRadius(Vector3 pos);
	// Genera una fuerza dada una particula.
	virtual Vector3 generateForce(Particle& par) = 0;
	// Update de ForceGenerator virtual.
	virtual void updateFGen(float t) = 0;


	//------

	//
	void isActive(bool act);
};