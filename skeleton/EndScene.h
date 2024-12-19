#pragma once

#include "Scene.h"

#include "ParticleSystem.h"


class EndScene : public Scene
{
private:

	int totalLevels = 0;
	int levelsWon = 0;

	ParticleSystem* smoke1 = nullptr;
	ParticleSystem* smoke2 = nullptr;

public:

	//------Constructoras y destructoras:

	// Constructora de EndScene.
	EndScene(PxPhysics* physics, PxScene* scene, GameManager* gm);
	// Destructora de EndScene.
	~EndScene();


	//------Metodos heredados:

	// Inicializacion de la escena.
	void initScene() override;
	// Update de EndScene.
	void updateScene(float t) override;
	// Activa la escena de EndScene.
	void activateScene() override;
	// Desactiva la escena de EndScene.
	void deactivateScene() override;
	// KeyPressed virtual de EndScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
};