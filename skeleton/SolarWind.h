#pragma once

#include "Particle.h"
#include "StaticRigidBody.h"
#include "WindForceGenerator.h"
#include "ForceSystem.h"
#include "ParticleSystem.h"

class Scene;

class SolarWind
{
private:

	WindForceGenerator* windGen = nullptr; // La fuerza del viento.

	Scene* myScene = nullptr; // Escena en la que esta.

public:

	//------Constructoras y destructoras:

	// Contructora base de SolarWind.
	SolarWind(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float radius, float windSpeed, Vector3 windDir, Scene* mScene);
	// Destructora de SolarWind.
	~SolarWind();


	//------Metodos importantes:

	// Settea si esta activo o no.
	void setActive(bool act);
};