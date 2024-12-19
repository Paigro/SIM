#include "Planet.h"


Planet::Planet(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float planetSize, Vector4 initColor, Scene* myScene)
{
	planetBody = new StaticRigidBody(gPhysics, gScene, PxTransform(initPos), CreateShape(physx::PxSphereGeometry(planetSize)), initColor, Vector3(planetSize, planetSize, planetSize));
	innerAthmosphere = new Particle(initPos, { 0, 0, 0 }, { 0, 0, 1, 0.5 }, planetSize * 3);
	outerAthmosphere = new Particle(initPos, { 0, 0, 0 }, { 0, 0, 1, 0.2 }, planetSize * 5);

	planetGravity = new TornadoForceGenerator(initPos, planetSize * 5, 0.25, { 0, 0, 1 }, planetSize * 3, 9.8);
	ForceSystem* forSys = new ForceSystem();
	forSys->addForceGenerator(planetGravity);
	myScene->addForceSistem(forSys);
}

Planet::~Planet()
{
	delete planetBody;
	delete innerAthmosphere;
	delete outerAthmosphere;
}

void Planet::setActive(bool act)
{
	planetBody->setActive(act);
	innerAthmosphere->setActive(act);
	outerAthmosphere->setActive(act);
	planetGravity->setActive(act);
}