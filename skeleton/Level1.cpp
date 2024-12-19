#include "Level1.h"


Level1::Level1(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj)
	: BaseLevelScene(physics, scene, gm, obj)
{

}

Level1::~Level1()
{
	delete blackHole;
}

void Level1::initScene()
{
	planet = new Planet(gPhysics, gScene, PLANET_POS, 15, Vector4(0.2, 0.2, 0.9, 1.0), this);
	blackHole = new BlackHole(gPhysics, gScene, BLACKHOLE_POS, 40, Vector3(0, 0, 1), this);

	BaseLevelScene::initScene();
}

void Level1::updateScene(float t)
{
	display_text = "LEVEL 1";
	display_text_position = Vector2(0, 450);
	display_text_color = Vector4(0, 0, 0, 1);

	BaseLevelScene::updateScene(t);
}
