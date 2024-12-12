#pragma once

#include "Scene.h"
#include "Canon.h"


class BaseLevelScene:public Scene
{
protected:

	Vector3 force; // Fuerza que se le aplica al disparo.
	float forceMultiplier; // Multiplcador de fuerza que se le aplica al disparo.

	Canon* canon = nullptr; // Referencia al canon.

public:

	//------Constructoras y destructoras:

	// Constructora de BaseLevelScene.
	BaseLevelScene(PxPhysics* physics, PxScene* scene);
	// Destructora de BaseLevelScene.
	~BaseLevelScene();


	//------Metodos heredados:

	// InitScene de BaseLevelScene.
	void initScene() override;
	// KeyPressed de BaseLevelScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	// Activa la escena.
	 void activateScene() override;
	// Desactiva la escena.
	 void deactivateScene() override;
};