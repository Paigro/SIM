#include "BlackHole.h"

BlackHole::BlackHole(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float holeSize, Scene* myScene)
{
	// He leido que la gravedad de un agujero negro puede ser 3 millones de veces la terrestre, yo voy a poner 1000.
	blackHoleBody = new TornadoForceGenerator(initPos, holeSize, 1.0, { 0, 0, 1 }, 1.0, 1000);
	ForceSystem* forSys = new ForceSystem();
	forSys->addForceGenerator(blackHoleBody);
	myScene->addForceSistem(forSys);

	ParticleSystem* parSys = new ParticleSystem(initPos, Vector3(0, 0, 0), 100, -1, 'G', Vector4(0.0, 0.0, 0.0, 1.0));
	myScene->addParticleSystem(parSys);
}

BlackHole::~BlackHole()
{

}

void BlackHole::setActive(bool act)
{
	//blackHoleBody->setActive(act);
}
