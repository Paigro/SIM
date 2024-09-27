#pragma once

#include <PxPhysicsAPI.h>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

class Particle
{
private:

	Vector3 vel; // velocidad de la particaula.
	physx::PxTransform pose; // Posicion de la particula. La pose tiene un Vector3 p y un cuaternion q.
	RenderItem* renderItem; // Renderitem de la particula.
	Vector3 acc; // Acceleracion de la particula.

public:

	//------Constructoras y destructoras:

	// Constructora de Particle con posicion y velocidad.
	Particle(Vector3 _pos, Vector3 _vel);
	// Constructora de Particle con posicion, velocidad y acceleracion.
	Particle(Vector3 _pos, Vector3 _vel, Vector3 _acc);
	// Destructora.
	~Particle();


	// Integrate con Euler.
	void integrate(float t);
};