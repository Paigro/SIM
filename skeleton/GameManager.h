#pragma once

#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

#include <iostream>

#include "SceneManager.h"

#include "InitScene.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Level4.h"


using namespace physx;


class GameManager
{
private:

	enum GAMESTATES
	{
		INIT, TUTO, LVL1, LVL2, LVL3, LVL4, WIN, LOST
	};

	PxPhysics* gPhysics = nullptr; // Referencia a la fisica.
	PxScene* gScene = nullptr; // Referencia a la escena fisica.

	SceneManager* sceneMg = nullptr; // Referencia al SceneManager.

	float levelTimer;
	float levelMaxTime;

	bool ejes;



	//------Metodos del GameManager:

	// Init del GameManager.
	void initGameManager();
	// Init de las escenas.
	void initScenes();





public:

	//------Constructoras y destructoras:

	// Constructora base de GameManager.
	GameManager(PxPhysics* physics, PxScene* scene);
	// Destructora de GameManager.
	~GameManager();


	//------Metodos importantes.

	
	// Update del GameManager.
	bool update(float t);
	// KeyPressed virtual de GameManager.
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera);
};