#include "GameManager.h"

#include "SceneManager.h"


GameManager::GameManager(PxPhysics* physics, PxScene* scene, SceneManager* sm)
	: gPhysics(physics), gScene(scene), sceneMg(sm)

{
	std::cout << "//--MENSAJE: GameManager creado." << std::endl;
	initGameManager();
}

GameManager::~GameManager()
{
	delete sceneMg;
}

void GameManager::initGameManager()
{
	actState = INIT;

	levelMaxTime = 60;
	levelTimer = 60;

	std::cout << "//--MENSAJE: GameManager inicializado." << std::endl;
}

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

	std::cout << actState << std::endl;
}

bool GameManager::update(float t)
{
	sceneMg->update(t);



	switch (actState)
	{
	case INIT: case TUTO: case MENU:
		gameManagerText = " ";
		gameManagerTextPos = Vector2(0, 490);

		break;
	case LVL1: case LVL2: case LVL3: case LVL4:

		if (levelTimer <= 0)
		{
			changeState();
		}
		else
		{
			levelTimer -= t;
		}
		gameManagerText = "Time left: " + std::to_string(levelTimer);
		gameManagerTextPos = Vector2(0, 490);
	default:
		break;
	}

	return true;
}

void GameManager::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case'C':
		if (sceneMg != nullptr)
		{
			//sceneMg->nextScene();
			//actState++;
			changeState();
		}
		break;
	case 'X':
		if (sceneMg != nullptr)
		{
			changeState();
			//sceneMg->prevScene();
			//actState--;
		}
		break;
	case 'Z':

	default:
		break;
	}

	if (actState > 7)
	{
		actState = 0;
	}
	if (actState < 0)
	{
		actState = 7;
	}




	// Esto no pero de momento si.
	if (sceneMg != nullptr)
	{
		sceneMg->keyPressed(key, camera);
	}
}

void GameManager::levelHasBeenLost()
{

}

void GameManager::levelHasBeenWon()
{

}