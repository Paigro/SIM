#include "Level2.h"


Level2::Level2(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj)
	: BaseLevelScene(physics, scene, gm, obj)
{

}

Level2::~Level2()
{
	delete solarWind;
}

void Level2::initScene()
{
	planet = new Planet(gPhysics, gScene, PLANET_POS, 15, Vector4(0.9, 0.4, 0.4, 1.0), this);
	solarWind = new SolarWind(gPhysics, gScene, WIND_POS, 150, 70, Vector3(0, -1, 0), this);

	BaseLevelScene::initScene();
}

void Level2::updateScene(float t)
{
	display_text = "LEVEL 2";
	display_text_position = Vector2(0, 450);
	display_text_color = Vector4(0, 0, 0, 1);

	display_text_2 = " ";
	display_text_position_2 = Vector2(210, 180);
	BaseLevelScene::updateScene(t);
}
