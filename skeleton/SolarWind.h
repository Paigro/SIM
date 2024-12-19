#pragma once

#include "Particle.h"
#include "StaticRigidBody.h"
#include "TornadoForceGenerator.h"
#include "ForceSystem.h"
#include "Scene.h"
#include "ParticleSystem.h"


class SolarWind
{
private:

	TornadoForceGenerator* blackHoleBody = nullptr; // El agujero negro.

public:

	//------Constructoras y destructoras:

	// Contructora base de SolarWind.
	SolarWind(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float holeSize, Scene* myScene, Vector3 axis);
	// Destructora de SolarWind.
	~SolarWind();


	//------Metodos importantes:

	// Settea si esta activo o no.
	void setActive(bool act);
};