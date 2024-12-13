#pragma once

#include "Scene.h"


class InitScene : public Scene
{
private:



public:

	//------Constructoras y destructoras:

	// Constructora de InitScene.
	InitScene(PxPhysics* physics, PxScene* scene);
	// Destructora de InitScene.
	~InitScene();


	//------Metodos heredados:

	// Inicializacion de la escena.
	void initScene() override;
	// Update de InitScene.
	void updateScene(float t) override;
	// Activa la escena de BaseLevelScene.
	void activateScene() override;
	// Desactiva la escena de BaseLevelScene.
	void deactivateScene() override;
	// KeyPressed virtual de InitScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
};