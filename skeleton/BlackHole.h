#pragma once

#include "Particle.h"
#include "StaticRigidBody.h"
#include "TornadoForceGenerator.h"
#include "ForceSystem.h"
#include "Scene.h"
#include "ParticleSystem.h"


class BlackHole
{
private:

	TornadoForceGenerator* blackHoleGen = nullptr; // La fuerza del agujero negro.

public:

	//------Constructoras y destructoras:

	// Contructora base de BlackHole.
	BlackHole(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float holeSize, Scene* myScene, Vector3 axis);
	// Destructora de BlackHole.
	~BlackHole();


	//------Metodos importantes:

	// Settea si esta activo o no.
	void setActive(bool act);
};