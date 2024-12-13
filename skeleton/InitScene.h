#pragma once

#include "Scene.h"


class InitScene : public Scene
{
private:



public:

	//------Constructoras y destructoras:

	// Constructora de InitScene.
	InitScene(PxPhysics* physics, PxScene* scene, int objetive);
	// Destructora de InitScene.
	~InitScene();


	//------Metodos heredados:

	// Inicializacion de la escena.
	virtual void initScene();
	// Update de InitScene.
	virtual void updateScene(float t);
	// Activa la escena de InitScene.
	virtual void activateScene();
	// Desactiva la escena de InitScene.
	virtual void deactivateScene();
	// KeyPressed virtual de InitScene.
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera);
};