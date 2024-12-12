#include "ParSysScene.h"


ParSysScene::ParSysScene(PxPhysics* physics, PxScene* scene)
	: Scene(physics, scene)
{

}

ParSysScene::~ParSysScene()
{

}

void ParSysScene::initScene()
{
	// Sistema de particulas:
	fountainParSys = new ParticleSystem(Vector3{ 100, 0, 0 }, Vector3{ 0, 30, 0 }, 200, 10, 'F');
	smokeParSys = new ParticleSystem(Vector3{ 0, 0, 100 }, Vector3{ 0, 30, 0 }, 200, -1, 'S');
	fireworkParSys = new ParticleSystem(Vector3{ 0, 100, 0 }, Vector3{ 0, 30, 0 }, 200, -1, 'W');
	randomParSys = new ParticleSystem(Vector3{ 0, 0, 0 }, Vector3{ 0, 0, 0 }, 10, -1, 'G'); // Se le puede meter color.

	addParticleSystem(fountainParSys);
	addParticleSystem(smokeParSys);
	addParticleSystem(fireworkParSys);
	addParticleSystem(randomParSys);
}

void ParSysScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	default:
		break;
	}
}