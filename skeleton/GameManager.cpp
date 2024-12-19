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
	totalLevels = 3;

	std::cout << "//--MENSAJE: GameManager inicializado." << std::endl;
}

#pragma endregion

#pragma region actualizacion de estados y textos:

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
	if (levelsResult.count(actState))
	{
		levelsResult[actState] = false;
	}
	else 
	{
		levelsResult.insert({ actState, false });
	}
	levelsEnded++;
	actState = MENU;
	sceneMg->changeScene(2);
}

void GameManager::levelHasBeenWon()
{
	if (levelsResult.count(actState))
	{
		levelsResult[actState] = true;
	}
	else 
	{
		levelsResult.insert({ actState, true });
	}
	levelsWon++;
	levelsEnded++;
	actState = MENU;
	sceneMg->changeScene(2);
}

std::map<int, bool> GameManager::getLevelResult()
{
	return levelsResult;
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
			levelTimer = LEVEL_TIME;
			levelHasBeenLost();
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
		case GameManager::LVL1: case GameManager::LVL2: case GameManager::LVL3:
			sceneMg->changeScene(2);
			actState = MENU;
			break;
		default:
			break;
		}

		break;
	case 49: case 50: case 51:
		if (actState == GameManager::MENU)
		{
			if (!levelsResult.count(key - 46))  // Si no esta en el mapa, cambia. No se resetean las escenas entonces si fallas fallas.
			{
				actState = key - 46;
				sceneMg->changeScene(actState);
			}
		}
		break;
	default:
		break;
	}


	levelTimer = LEVEL_TIME;

	// Esto no pero de momento si. Si va aqui donde si no.
	if (sceneMg != nullptr)
	{
		sceneMg->keyPressed(key, camera);
	}
}

#pragma endregion