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
	float damping;

public:

	//------Constructoras y destructoras:

	// Constructora de Particle con posicion y velocidad.
	Particle(Vector3 _pos, Vector3 _vel);
	// Constructora de Particle con posicion, velocidad y acceleracion.
	Particle(Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam);
	// Destructora.
	~Particle();


	//------Getters y setters:

	// Devuelve la velocidad.
	Vector3 getVel() const { return vel; }
	// devuelve la posicion (Vector3).
	Vector3 getPos() const { return pose.p; }
	// Devuelve la aceleracion.
	Vector3 getAcc() const { return acc; }
	// Devuelve el dumping.
	float getDamping() const { return damping; }
	// Settea el color de la particula.
	void setColor(float _r, float _g, float _b, float _w);

	//------Metodos de movimiento:

	// Integrate con Euler normal.
	void integrate(float t);
};