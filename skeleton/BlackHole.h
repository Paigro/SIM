#pragma once

#include "Particle.h"
#include "StaticRigidBody.h"
#include "TornadoForceGenerator.h"
#include "ForceSystem.h"
#include "ParticleSystem.h"

class Scene;


class BlackHole
{
private:

	float size; // Tamanyo del agujero negro (radio).

	TornadoForceGenerator* blackHoleGen = nullptr; // La fuerza del agujero negro.

	Scene* myScene = nullptr; // Escena en la que esta.

public:

	//------Constructoras y destructoras:

	// Contructora base de BlackHole.
	BlackHole(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float holeSize, Vector3 axis, Scene* mScene);
	// Destructora de BlackHole.
	~BlackHole();


	//------Metodos importantes:

	// Settea si esta activo o no.
	void setActive(bool act);


	//------Getters y setters:

	// Devuelve el radio de accion del agujero negro.
	float getRadius() { return size; }
};