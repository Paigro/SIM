#include "Level1.h"


Level1::Level1(PxPhysics* physics, PxScene* scene, int obj)
	: BaseLevelScene(physics, scene, obj)
{

}

Level1::~Level1()
{
	BaseLevelScene::~BaseLevelScene();
}