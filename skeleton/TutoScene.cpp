#include "TutoScene.h"


TutoScene::TutoScene(PxPhysics* physics, PxScene* scene, GameManager* gm)
	: Scene(physics, scene, gm)
{

}

void TutoScene::initScene()
{
	/*Particle* button1 = new Particle(Vector3(-115.0, -30.0f, 0.0), Vector3(0, 0, 0), Vector4(1, 1, 1, 1));
	button1->changeShape(CreateShape(PxCapsuleGeometry(20, 10)));
	button1->setLifeTime(-1);


	Particle* button2 = new Particle(Vector3(-115.0, 30.0f, 0.0), Vector3(0, 0, 0), Vector4(1, 1, 1, 1));
	button2->changeShape(CreateShape(PxCapsuleGeometry(20, 10)));
	button2->setLifeTime(-1);


	addParticle(button1);
	addParticle(button2);*/
}

void TutoScene::updateScene(float t)
{
	display_text = "Tutorial";
	display_text_position = Vector2(200, 315);
	display_text_color = Vector4(0, 0, 0, 1);

	display_text_2 = "Tutorial";
	display_text_position_2 = Vector2(210, 180);
}

void TutoScene::activateScene()
{
	Scene::activateScene();
}

void TutoScene::deactivateScene()
{
	Scene::deactivateScene();
}

void TutoScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	default:
		break;
	}
}