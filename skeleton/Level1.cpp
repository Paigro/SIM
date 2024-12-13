#include "Level1.h"


Level1::Level1(PxPhysics* physics, PxScene* scene, int obj)
	: BaseLevelScene(physics, scene, obj)
{

}

Level1::~Level1()
{
	BaseLevelScene::~BaseLevelScene();
}

void Level1::updateScene(float t)
{
	display_text = "LEVEL 1";
	display_text_position = Vector2(512 / 2, 512 / 2);
	display_text_color = Vector4(0, 0, 0, 1);

	display_text_2 = " ";
	display_text_position_2 = Vector2(210, 180);
}
