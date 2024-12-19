#pragma once

#include "Scene.h"
#include "FlotationForceGenerator.h"
#include "ForceSystem.h"


class LevelsScene : public Scene
{
private:

	std::map<int, bool> levelsResult;

	Particle* lvl1 = nullptr;
	Particle* lvl2 = nullptr;
	Particle* lvl3 = nullptr;

	Particle* sea = nullptr;


	//------Metodos de LevelsScene:

	//
	void checkResults();

public:

	//------Constructoras y destructoras:

	// Constructora de LevelsScene.
	LevelsScene(PxPhysics* physics, PxScene* scene, GameManager* gm);
	// Destructora de LevelsScene.
	~LevelsScene();


	//------Metodos heredados:

	// Inicializacion de la escena.
	void initScene() override;
	// Update de LevelsScene.
	void updateScene(float t) override;
	// Activa la escena de LevelsScene.
	void activateScene() override;
	// Desactiva la escena de LevelsScene.
	void deactivateScene() override;
	// KeyPressed virtual de LevelsScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
};