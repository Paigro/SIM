#include "ExplosionScene.h"


ExplosionScene::ExplosionScene(PxPhysics* physics, PxScene* scene)
	: Scene(physics, scene)
{

}

ExplosionScene::~ExplosionScene()
{

}

void ExplosionScene::initScene()
{
	// Sistema de particulas aleatorias.
	addParticleSystem(new ParticleSystem(Vector3{ 0, 0, 0 }, Vector3{ 0, 0, 0 }, 200, -1, 'G', Vector4(0.64, 0.12, 0.09, 1.0)));

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