#pragma once

#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

#include <iostream>

#include <map>

class SceneManager;


using namespace physx;

constexpr float LEVEL_TIME = 60.0; // Tiempo para completar el nivel.


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

	float levelTimer; // Tiempo que dura un nivel.

	int actState; // Estado actual de juego.

	int totalLevels;
	int levelsWon;
	int levelsEnded = 0;

	std::map<int, bool> levelsResult;


	//------Metodos internos del GameManager:

	// Init del GameManager.
	void initGameManager();
	// Para setterar los textos.
	void setTexts();




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
	// 
	std::map<int, bool> getLevelResult();
};