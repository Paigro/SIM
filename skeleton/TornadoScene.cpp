#include "TornadoScene.h"


TornadoScene::TornadoScene(PxPhysics* physics, PxScene* scene)
	: Scene(physics, scene)
{

}

TornadoScene::~TornadoScene()
{

}

void TornadoScene::initScene()
{
	// Sistema de particulas aleatorias.
	addParticleSystem(new ParticleSystem(Vector3{ 0, 0, 0 }, Vector3{ 0, 0, 0 }, 200, -1, 'G', Vector4(0.54, 0.58, 0.59, 1.0)));

	// Sistema de fuerzas.
	ForceSystem* forSys = new ForceSystem();

	// Tornado.
	tornadoGen = new TornadoForceGenerator(Vector3{ 0, 0, 0 }, 400);

	// Se la metemos al sistema.
	forSys->addForceGenerator(tornadoGen);

	// Se lo metemos a la escena.
	addForceSistem(forSys);
}

void TornadoScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	default:
		break;
	}
}