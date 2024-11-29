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
	WindScene();
	// Destructora de WindScene.
	~WindScene();


	//------Metodos heredados:

	// KeyPressed de WindScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	// InitScene de WindScene.
	void initScene() override;
};