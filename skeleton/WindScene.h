#pragma once

#include "Scene.h"
#include "RandomGenerator.h"
#include "WindForceGenerator.h"


class WindScene : public Scene
{
private:

	WindForceGenerator* windGen = nullptr; // Generador de viendo.

	bool windActive = false; // Para controlar el viento.

public:

	//------Constructoras y destructoras:

	// Constructora de WindScene.
	WindScene(PxPhysics* physics, PxScene* scene);
	// Destructora de WindScene.
	~WindScene();


	//------Metodos heredados:

	// InitScene de WindScene.
	void initScene() override;
	// KeyPressed de WindScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
};