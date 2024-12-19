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

	TornadoForceGenerator* blackHoleBody = nullptr; // El agujero negro.

public:

	//------Constructoras y destructoras:

	// Contructora base de BlackHole.
	BlackHole(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float holeSize, Scene* myScene);
	// Destructora de Planet.
	~BlackHole();


	//------Metodos importantes:

	// Settea si esta activo o no.
	void setActive(bool act);
};