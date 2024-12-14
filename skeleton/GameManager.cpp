#include "GameManager.h"

GameManager::GameManager(PxPhysics* physics, PxScene* scene)
	: gPhysics(physics), gScene(scene)

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
	sceneMg = new SceneManager();

	initScenes();

	std::cout << "//--MENSAJE: GameManager inicializado." << std::endl;
}

void GameManager::initScenes()
{
	// Escenas del proyecto final:
	sceneMg->addScene(new InitScene(gPhysics, gScene));
	sceneMg->addScene(new Level1(gPhysics, gScene, 4));

	//level 2
	//level 3
	//level 4
	//winlevel
	//loose level
	//tuto
	//end

	std::cout << "//--MENSAJE: Escenas creadas." << std::endl;
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
	default:
		break;
	}

	// Esto no pero de momento si.
	if (sceneMg != nullptr)
	{
		sceneMg->keyPressed(key, camera);
	}
}
