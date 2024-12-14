#pragma once

#include "Scene.h"


class TutoScene : public Scene
{
private:



public:

	//------Constructoras y destructoras:

	// Constructora de TutoScene.
	TutoScene(PxPhysics* physics, PxScene* scene, GameManager* gm);
	// Destructora de InitScene.
	~TutoScene();


	//------Metodos heredados:

	// Inicializacion de la escena.
	void initScene() override;
	// Update de TutoScene.
	void updateScene(float t) override;
	// Activa la escena de TutoScene.
	void activateScene() override;
	// Desactiva la escena de TutoScene.
	void deactivateScene() override;
	// KeyPressed virtual de TutoScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
};