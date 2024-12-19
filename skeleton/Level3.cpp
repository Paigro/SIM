#include "Level3.h"


Level3::Level3(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj)
	: BaseLevelScene(physics, scene, gm, obj)
{

}

Level3::~Level3()
{
	
}

void Level3::updateScene(float t)
{
	display_text = "LEVEL 3";
	display_text_position = Vector2(512 / 2, 512 / 2);
	display_text_color = Vector4(0, 0, 0, 1);

	display_text_2 = " ";
	display_text_position_2 = Vector2(210, 180);
	BaseLevelScene::updateScene(t);
}
