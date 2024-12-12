#pragma once

#include "Scene.h"
#include "Canon.h"


class BaseLevelScene :public Scene
{
protected:

	Canon* canon = nullptr; // Referencia al canon.

	Vector3 force; // Fuerza que se le aplica al disparo.
	float forceMultiplier; // Multiplicador de fuerza que se le aplica al disparo.

	int objetive; // Numero de satelites que hay que poner en orbita.

	bool canShoot = true; // Cooldown del disparo.
	float shootRecharge = 0; // Cooldown del disparo.

public:

	//------Constructoras y destructoras:

	// Constructora de BaseLevelScene.
	BaseLevelScene(PxPhysics* physics, PxScene* scene, int objetive);
	// Destructora de BaseLevelScene.
	~BaseLevelScene();


	//------Metodos heredados:

	// Inicializacion de la escena.
	virtual void initScene();
	// Update de BaseLevelScene.
	virtual void updateScene(float t);
	// Activa la escena de BaseLevelScene.
	virtual void activateScene();
	// Desactiva la escena de BaseLevelScene.
	virtual void deactivateScene();
	// KeyPressed virtual de BaseLevelScene.
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera);
};