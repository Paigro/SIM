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
}

void BaseLevelScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
}
