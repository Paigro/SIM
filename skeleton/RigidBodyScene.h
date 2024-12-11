#pragma once

#include "Scene.h"
#include "DinamicRigidBody.h"
#include "StaticRigidBody.h"

class RigidBodyScene : public Scene
{
private:

public:

	//------Constructoras y destructoras:

	// Constructora de RigidBodyScene.
	RigidBodyScene();
	// Destructora de RigidBodyScene.
	~RigidBodyScene();


	//------Metodos heredados:

	// KeyPressed de RigidBodyScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	// InitScene de RigidBodyScene.
	void initScene() override;
};