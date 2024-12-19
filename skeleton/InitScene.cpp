#include "InitScene.h"


InitScene::InitScene(PxPhysics* physics, PxScene* scene, GameManager* gm)
	: Scene(physics, scene, gm)
{

}

InitScene::~InitScene()
{

}

void InitScene::initScene()
{
	Particle* button1 = new Particle(Vector3(-115.0, -30.0f, 0.0), Vector3(0, 0, 0), Vector4(1, 1, 1, 1));
	button1->changeShape(CreateShape(PxCapsuleGeometry(20, 10)));
	button1->setLifeTime(-1);
	button1->setGravitable(false);
	button1->setMovible(false);


	Particle* button2 = new Particle(Vector3(-115.0, 30.0f, 0.0), Vector3(0, 0, 0), Vector4(1, 1, 1, 1));
	button2->changeShape(CreateShape(PxCapsuleGeometry(20, 10)));
	button2->setLifeTime(-1);
	button2->setGravitable(false);
	button2->setMovible(false);


	addParticle(button1);
	addParticle(button2);
}

void InitScene::updateScene(float t)
{
	display_text = "EMPEZAR (c)";
	display_text_position = Vector2(200, 315);
	display_text_color = Vector4(0, 0, 0, 1);

	display_text_2 = "SALIR (exit)";
	display_text_position_2 = Vector2(210, 180);

	Scene::updateScene(t);
}

void InitScene::activateScene()
{
	Scene::activateScene();
}

void InitScene::deactivateScene()
{
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