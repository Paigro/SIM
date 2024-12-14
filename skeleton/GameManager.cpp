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

	std::cout << "//--MENSAJE: GameManager inicializado." << std::endl;
}



void GameManager::changeState()
{
	switch (actState)
	{
	case GameManager::INIT:
		sceneMg->changeScene(1);
		break;
	case GameManager::TUTO:
		sceneMg->changeScene(2);
		break;
	case GameManager::LVL1:
		sceneMg->changeScene(2);
		break;
	case GameManager::LVL2:
		sceneMg->changeScene(2);
		break;
	case GameManager::LVL3:
		sceneMg->changeScene(2);
		break;
	case GameManager::LVL4:
		sceneMg->changeScene(2);
		break;
	default:
		break;
	}
}

bool GameManager::update(float t)
{
	sceneMg->update(t);

	return true;
}

void GameManager::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case'C':
		if (sceneMg != nullptr)
		{
			sceneMg->nextScene();
		}
		break;
	case 'X':
		if (sceneMg != nullptr)
		{
			sceneMg->prevScene();
		}
		break;
	case 'Z':

	default:
		break;
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