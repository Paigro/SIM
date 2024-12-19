#include "GameManager.h"

#include "SceneManager.h"


#pragma region constructoras y destructoras:

GameManager::GameManager(PxPhysics* physics, PxScene* scene, SceneManager* sm)
	: gPhysics(physics), gScene(scene), sceneMg(sm)

{
	std::cout << "//--MENSAJE: GameManager creado." << std::endl;
	initGameManager();
}

GameManager::~GameManager()
{
	delete sceneMg;
	std::cout << "//--MENSAJE: GameManager eliminado." << std::endl;
}

#pragma endregion

#pragma region inicializacion:

void GameManager::initGameManager()
{
	actState = INIT;

	levelTimer = LEVEL_TIME;
	levelsWon = 0;
	totalLevels = 4;

	std::cout << "//--MENSAJE: GameManager inicializado." << std::endl;
}

#pragma endregion

#pragma region actualizacion de estados y textos:

void GameManager::changeState()
{
	switch (actState)
	{
	case GameManager::INIT:
		sceneMg->changeScene(1);
		actState = TUTO;
		break;
	case GameManager::TUTO:
		sceneMg->changeScene(2);
		actState = MENU;
		break;
	case MENU:
		sceneMg->changeScene(3);
		actState = LVL1;
		break;
	case GameManager::LVL1:
		sceneMg->changeScene(4);
		actState = LVL2;
		break;
	case GameManager::LVL2:
		sceneMg->changeScene(5);
		actState = LVL3;
		break;
	case GameManager::LVL3:
		sceneMg->changeScene(6);
		actState = LVL4;
		break;
	case GameManager::LVL4:
		sceneMg->changeScene(0);
		actState = INIT;
		break;
	default:
		break;
	}
}

void GameManager::setTexts()
{
	switch (actState)
	{
	case INIT: case TUTO:
		gameManagerText = " ";
		break;
	case MENU:
		gameManagerText = "You win: " + std::to_string(levelsWon) + " / " + std::to_string(totalLevels);
		break;
	case LVL1: case LVL2: case LVL3: case LVL4:
		gameManagerText = "Time left: " + std::to_string(levelTimer);
	default:
		break;
	}
	gameManagerTextPos = Vector2(0, 490);
}

void GameManager::levelHasBeenLost()
{
	changeState();
}

void GameManager::levelHasBeenWon()
{
	levelsWon++;
	changeState();
}

#pragma endregion

#pragma region update y keyPressed:

bool GameManager::update(float t)
{
	sceneMg->update(t);// Se actualizan las escenas.

	switch (actState)
	{
	case LVL1: case LVL2: case LVL3: case LVL4:
		if (levelTimer <= 0)
		{
			changeState();
			levelTimer = LEVEL_TIME;
		}
		else
		{
			levelTimer -= t;
		}
	default:
		break;
	}

	setTexts();

	return true;
}

void GameManager::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case 'C': // Para avanzar al siguiente nivel.
		if (sceneMg != nullptr)
		{
			changeState();
		}
		break;
	case 'M': // Para debugear e ir a la siguiente escena.
		if (sceneMg != nullptr)
		{
			sceneMg->nextScene();
			actState++;
		}
		break;
	case 'N': // Para debugear e ir a la anterior escena.
		if (sceneMg != nullptr)
		{
			sceneMg->prevScene();
			actState--;
		}
		break;
	default:
		break;
	}

	// Para debug.
	if (actState > 7)
	{
		actState = 0;
	}
	if (actState < 0)
	{
		actState = 7;
	}

	// Esto no pero de momento si. Si va aqui donde si no.
	if (sceneMg != nullptr)
	{
		sceneMg->keyPressed(key, camera);
	}
}

#pragma endregion