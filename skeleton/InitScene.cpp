#include "InitScene.h"


InitScene::InitScene(PxPhysics* physics, PxScene* scene)
	: Scene(physics, scene)
{
	/*display_text = "hola";
	display_text_color = Vector4(0, 1, 1, 1);
	display_text_position = Vector2(20, 100);*/
}

void InitScene::initScene()
{
	
}

void InitScene::updateScene(float t)
{

}

void InitScene::activateScene()
{
	/*display_text = "hola";
	display_text_color = Vector4(0, 1, 1, 1);
	display_text_position = Vector2(20, 100);*/
	Scene::activateScene();
}

void InitScene::deactivateScene()
{
	//display_text = " ";
	Scene::deactivateScene();
}

void InitScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	default:
		break;
	}
}