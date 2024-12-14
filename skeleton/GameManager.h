#pragma once

#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

#include <iostream>

//#include "SceneManager.h"

class SceneManager;


using namespace physx;


class GameManager
{
private:

	enum GAMESTATES
	{
		INIT, TUTO, MENU, LVL1, LVL2, LVL3, LVL4
	};

	PxPhysics* gPhysics = nullptr; // Referencia a la fisica.
	PxScene* gScene = nullptr; // Referencia a la escena fisica.

	SceneManager* sceneMg = nullptr; // Referencia al SceneManager.

	float levelTimer;
	float levelMaxTime;

	bool ejes;

	int actState;



	//------Metodos del GameManager:

	// Init del GameManager.
	void initGameManager();

	//
	void changeState();





public:

	//------Constructoras y destructoras:

	// Constructora base de GameManager.
	GameManager(PxPhysics* physics, PxScene* scene, SceneManager* sm);
	// Destructora de GameManager.
	~GameManager();


	//------Metodos importantes.

	// Update del GameManager.
	bool update(float t);
	// KeyPressed virtual de GameManager.
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera);


	//------Metodos para el cambio de estado:

	//
	void levelHasBeenLost();
	//
	void levelHasBeenWon();
};