#include "BlackHole.h"

BlackHole::BlackHole(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float holeSize, Scene* myScene)
{
	// He leido que la gravedad de un agujero negro puede ser 3 millones de veces la terrestre, yo voy a poner 40 porque si no es demasiado.
	blackHoleBody = new TornadoForceGenerator(initPos, holeSize, 1.0, { 0, 0, 1 }, 1.0, 40);
	ForceSystem* forSys = new ForceSystem();
	forSys->addForceGenerator(blackHoleBody);
	myScene->addForceSistem(forSys);

	ParticleSystem* parSys = new ParticleSystem(new RandomGenerator(initPos, { 0,0,0 }, 50, -1, -1, -holeSize / 1.5, holeSize / 1.5, Vector4(0.0, 0.0, 0.0, 1.0), Vector3(1, 1, 0), false, 0.5), -1);
	myScene->addParticleSystem(parSys);
}

BlackHole::~BlackHole()
{

}

void BlackHole::setActive(bool act)
{
	//blackHoleBody->setActive(act);
}
