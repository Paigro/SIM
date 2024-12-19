#pragma once

#include "Particle.h"
#include "StaticRigidBody.h"
#include "TornadoForceGenerator.h"
#include "ForceSystem.h"

class Scene;


class Planet
{
private:

	Vector3 position;

	float size;

	StaticRigidBody* planetBody = nullptr; // El planeta rocoso como tal.

	Particle* innerAthmosphere = nullptr; // La atmosfera minima para hacer orbita.
	Particle* outerAthmosphere = nullptr; // La atmosfera maxima para hacer orbita.

	TornadoForceGenerator* planetGravity = nullptr; // La gravedad del planeta.

	Scene* myScene = nullptr; // Escena en la que esta.

public:

	//------Constructoras y destructoras:

	// Contructora base de Planet.
	Planet(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float planetSize, Vector4 initColor, Scene* mScene);
	// Destructora de Planet.
	~Planet();


	//------Metodos importantes:

	// Settea si esta activo o no.
	void setActive(bool act);


	//------Getters y setters:

	//
	float getInnerRadius() { return size * 2.7; }
	// 
	float getMaxRadius() { return size * 5; }
};