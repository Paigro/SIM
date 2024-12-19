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
	planet = new Planet(gPhysics, gScene, Vector3(-150, 0, 0), 15, Vector4(0.2, 0.2, 0.9, 1.0), this);
	blackHole = new BlackHole(gPhysics, gScene, Vector3(-60, 30, 0), 40, Vector3(0, 0, 1), this);

	BaseLevelScene::initScene();
}

void Level1::updateScene(float t)
{
	display_text = "LEVEL 1";
	display_text_position = Vector2(512 / 2, 512 / 2);
	display_text_color = Vector4(0, 0, 0, 1);

	display_text_2 = " ";
	display_text_position_2 = Vector2(210, 180);
	BaseLevelScene::updateScene(t);
}
