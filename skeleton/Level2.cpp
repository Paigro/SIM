#include "Level2.h"


Level2::Level2(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj)
	: BaseLevelScene(physics, scene, gm, obj)
{

}

Level2::~Level2()
{
	
}

void Level2::updateScene(float t)
{
	display_text = "LEVEL 2";
	display_text_position = Vector2(512 / 2, 512 / 2);
	display_text_color = Vector4(0, 0, 0, 1);

	display_text_2 = " ";
	display_text_position_2 = Vector2(210, 180);
	BaseLevelScene::updateScene(t);
}
