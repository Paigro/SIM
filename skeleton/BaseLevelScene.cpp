#include "BaseLevelScene.h"

BaseLevelScene::BaseLevelScene(PxPhysics* physics, PxScene* scene)
	: Scene(physics, scene)
{

}

BaseLevelScene::~BaseLevelScene()
{
}

void BaseLevelScene::initScene()
{
	canon = new Canon(gPhysics, gScene, Vector3(0, 0, 0), 4);
}

void BaseLevelScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	default:
		break;
	}
}

void BaseLevelScene::activateScene()
{
	canon->setActive(true);
	Scene::activateScene();
}

void BaseLevelScene::deactivateScene()
{
	canon->setActive(false);
	Scene::deactivateScene();
}
