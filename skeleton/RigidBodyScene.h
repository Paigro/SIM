#pragma once

#include "Scene.h"
#include "DinamicRigidBody.h"
#include "StaticRigidBody.h"

class RigidBodyScene : public Scene
{
private:

	StaticRigidBody* floor = nullptr; // Suelo de la escena.
	DinamicRigidBody* cube = nullptr; // Un cubo.
	DinamicRigidBody* otherCube = nullptr; // Otro cubo.

public:

	//------Constructoras y destructoras:

	// Constructora de RigidBodyScene.
	RigidBodyScene(PxPhysics* physics, PxScene* scene);
	// Destructora de RigidBodyScene.
	~RigidBodyScene();


	//------Metodos heredados:

	// InitScene de RigidBodyScene.
	void initScene() override;
	// KeyPressed de RigidBodyScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
};