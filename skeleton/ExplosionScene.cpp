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

	// Sistema de fuerzas.
	ForceSystem* forSys = new ForceSystem();

	// Explosion.
	explosionGen = new ExplosionForceGenerator(Vector3{ 0, 0, 0 }, 0, 20, 40);

	// Se la metemos al sistema.
	forSys->addForceGenerator(explosionGen);

	// Se lo metemos a la escena.
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