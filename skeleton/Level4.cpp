#include "Level4.h"


Level4::Level4(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj)
	: BaseLevelScene(physics, scene, gm, obj)
{

}

Level4::~Level4()
{
	
}

void Level4::updateScene(float t)
{
	display_text = "LEVEL 4";
	display_text_position = Vector2(512 / 2, 512 / 2);
	display_text_color = Vector4(0, 0, 0, 1);

	display_text_2 = " ";
	display_text_position_2 = Vector2(210, 180);
	BaseLevelScene::updateScene(t);
}
