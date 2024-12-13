#pragma once

#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

#include <iostream>

#include "SceneManager.h"

using namespace physx;


class GameManager
{
private:



public:

	//------Constructoras y destructoras:

	// Constructora base de GameManager.
	GameManager(PxPhysics* physics, PxScene* scene);
	// Destructora de GameManager.
	~GameManager();


	// Update del GameManager.
	bool update(float t);
	// KeyPressed virtual de GameManager.
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera);
};