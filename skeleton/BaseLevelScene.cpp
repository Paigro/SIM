#include "BaseLevelScene.h"

BaseLevelScene::BaseLevelScene(PxPhysics* physics, PxScene* scene, int obj)
	: Scene(physics, scene), objetive(obj)
{
	direction = { 0, 0, 0 };
	angle = 0;
	baseForce = { 1000, 0, 0 };
	forceMultiplier = 1;
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
		canon->prepareSoot();
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
				bullet->addForce(calculateForce());
				addRigidBody(bullet);
				canShoot = false;
			}
		}
		break;
	case 'W':
		if (angle < 60)
		{
			angle += 5;
		}
		break;
	case 'A':
		if (forceMultiplier > 1)
		{
			forceMultiplier -= 1;
		}
		break;
	case 'S':
		if (angle > -60)
		{
			angle -= 5;
		}
		break;
	case 'D':
		if (forceMultiplier < 10)
		{
			forceMultiplier += 1;
		}
		break;
	default:
		break;
	}
	std::cout << "Canon dispara a " << angle << "º y con multiplayer " << forceMultiplier << "*4000." << std::endl;
}

Vector3 BaseLevelScene::calculateForce()
{
	Vector3 force(0, 0, 0);

	direction.x = -cos(angle * (3.1416 / 180.0));
	direction.y = sin(angle * (3.1416 / 180.0));
	direction.z = 0;

	force = direction * (forceMultiplier * 4000);

	return force;
}

void BaseLevelScene::activateScene()
{
	if (canon != nullptr)
	{
		canon->setActive(true);
	}
	Scene::activateScene();
}

void BaseLevelScene::deactivateScene()
{
	if (canon != nullptr)
	{
		canon->setActive(false);
	}
	Scene::deactivateScene();
}
