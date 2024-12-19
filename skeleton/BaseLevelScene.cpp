#include "BaseLevelScene.h"


BaseLevelScene::BaseLevelScene(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj)
	: Scene(physics, scene, gm), objetive(obj)
{
	direction = { 0, 0, 0 };
	angle = 0;
	baseForce = SHOOT_FORCE;
	forceMultiplier = 1;
	display_text = "INIT SCENE";
	display_text_color = Vector4(0, 1, 1, 1);
	display_text_position = Vector2(20, 100);
}

BaseLevelScene::~BaseLevelScene()
{
	delete canon;
	delete planet;
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
	char r = toupper(key);
	switch (toupper(key))
	{
	case ' ': // Disparo.
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
	case '\r': // Meter mas disparos.
		canon->addShoots(1);
		break;

	case 'W':
		if (angle < 60)
		{
			angle += 10;
			std::cout << "Canon dispara a " << angle << "grados y con multiplayer " << forceMultiplier << " * " << baseForce << std::endl;
		}
		break;
	case 'A':
		if (forceMultiplier > 1)
		{
			forceMultiplier -= 1;
			std::cout << "Canon dispara a " << angle << "grados y con multiplayer " << forceMultiplier << " * " << baseForce << std::endl;
		}
		break;
	case 'S':
		if (angle > -60)
		{
			angle -= 10;
			std::cout << "Canon dispara a " << angle << "grados y con multiplayer " << forceMultiplier << " * " << baseForce << std::endl;
		}
		break;
	case 'D':
		if (forceMultiplier < 10)
		{
			forceMultiplier += 1;
			std::cout << "Canon dispara a " << angle << "grados y con multiplayer " << forceMultiplier << " * " << baseForce << std::endl;
		}
		break;
	default:
		break;
	}
}

Vector3 BaseLevelScene::calculateForce()
{
	Vector3 force(0, 0, 0);

	direction.x = -cos(angle * (3.1416 / 180.0));
	direction.y = sin(angle * (3.1416 / 180.0));
	direction.z = 0;

	force = direction * (forceMultiplier * baseForce);

	return force;
}

void BaseLevelScene::activateScene()
{
	if (canon != nullptr)
	{
		canon->setActive(true);
	}
	if (planet != nullptr)
	{
		planet->setActive(true);
	}
	Scene::activateScene();
}

void BaseLevelScene::deactivateScene()
{
	if (canon != nullptr)
	{
		canon->setActive(false);
	}
	if (planet != nullptr)
	{
		planet->setActive(false);
	}
	Scene::deactivateScene();
}