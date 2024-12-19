#pragma once

#include "Particle.h"
#include "StaticRigidBody.h"
#include "TornadoForceGenerator.h"
#include "ForceSystem.h"
#include "Scene.h"


class Planet
{
private:

	StaticRigidBody* planetBody = nullptr; // El planeta rocoso como tal.

	Particle* innerAthmosphere = nullptr; // La atmosfera minima para hacer orbita.
	Particle* outerAthmosphere = nullptr; // La atmosfera maxima para hacer orbita.

	TornadoForceGenerator* planetGravity = nullptr; // La gravedad del planeta.

public:

	//------Constructoras y destructoras:

	// Contructora base de Planet.
	Planet(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float planetSize, Vector4 initColor, Scene* myScene);
	// Destructora de Planet.
	~Planet();


	//------Metodos importantes:

	// Settea si esta activo o no.
	void setActive(bool act);
};