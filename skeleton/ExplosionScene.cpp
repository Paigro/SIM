#include "ExplosionScene.h"

ExplosionScene::ExplosionScene()
	: Scene()
{



}

ExplosionScene::~ExplosionScene()
{



}

void ExplosionScene::initScene()
{
	// Sistema de particulas aleatorias.
	addParticleSystem(new ParticleSystem(Vector3{ 0, 0, 0 }, Vector3{ 0, 0, 0 }, 200, -1, 'G'));

	ForceSystem* forSys = new ForceSystem();

	explosionGen = new ExplosionForceGenerator(Vector3{ 0, 0, 0 }, 0, 20, 40);
	forSys->addForceGenerator(explosionGen);

	addForceSistem(forSys);
}

void ExplosionScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case 'B':
		explosionGen->resetExplosion();
		break;
	default:
		break;
	}
}