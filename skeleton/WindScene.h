#pragma once

#include "Scene.h"
#include "RandomGenerator.h"
#include "WindForceGenerator.h"

class WindScene : public Scene
{
private:

	WindForceGenerator* windGen = nullptr;

public:

	//------Constructoras y destructoras:

	// Constructora de WindScene.
	WindScene();
	// Destructora de WindScene.
	~WindScene();


	//------Metodos heredados:

	//
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	//
	void initScene() override;
};