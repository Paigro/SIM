#include "BaseLevelScene.h"

BaseLevelScene::BaseLevelScene(PxPhysics* physics, PxScene* scene, int obj)
	: Scene(physics, scene), objetive(obj)
{

}

BaseLevelScene::~BaseLevelScene()
{
}

void BaseLevelScene::initScene()
{
	canon = new Canon(gPhysics, gScene, Vector3(0, 0, 0), objetive);
}

void BaseLevelScene::updateScene(float t)
{
	if (!canShoot)
	{
		shootRecharge += t;
	}
	if (shootRecharge >= 2.0)
	{
		canShoot = true;
		shootRecharge = 0;
	}

	Scene::updateScene(t);
}

void BaseLevelScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case 'O':
		if (canon != nullptr && canShoot)
		{
			DinamicRigidBody* bullet = canon->shoot();
			if (bullet != nullptr)
			{
				bullet->setPose(PxTransform(bullet->getPose().p + Vector3(-4, 0, 0)));
				bullet->addForce(Vector3(-10000, 0, 0));
				addRigidBody(bullet);
				canon->prepareSoot();
				canShoot = false;
			}
		}
		break;
	default:
		break;
	}
}

void BaseLevelScene::activateScene()
{
	canon->setActive(true);
	Scene::activateScene();
}

void BaseLevelScene::deactivateScene()
{
	canon->setActive(false);
	Scene::deactivateScene();
}
