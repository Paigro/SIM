#pragma once

#include "Scene.h"
#include "RandomGenerator.h"
#include "ExplosionForceGenerator.h"

class ExplosionScene : public Scene
{
private:

	ExplosionForceGenerator* explosionGen = nullptr;

public:

	//------Constructoras y destructoras:

	// Constructora de ExplosionScene.
	ExplosionScene();
	// Destructora de ExplosionScene.
	~ExplosionScene();


	//------Metodos heredados:

	//
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	//
	void initScene() override;
};