#include "TornadoScene.h"


TornadoScene::TornadoScene()
	: Scene()
{

}

TornadoScene::~TornadoScene()
{

}

void TornadoScene::initScene()
{
	// Sistema de particulas aleatorias.
	addParticleSystem(new ParticleSystem(Vector3{ 0, 0, 0 }, Vector3{ 0, 0, 0 }, 200, -1, 'G'));

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