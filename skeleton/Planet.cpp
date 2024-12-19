#include "Planet.h"

#include "Scene.h"


Planet::Planet(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float planetSize, Vector4 initColor, Scene* mScene)
	: myScene(mScene), position(initPos), size(planetSize)
{
	planetBody = new StaticRigidBody(gPhysics, gScene, PxTransform(position), CreateShape(physx::PxSphereGeometry(size)), initColor, Vector3(size, size, size));
	//innerAthmosphere = new Particle(position, { 0, 0, 0 }, { 0, 0, 1, 0.5 }, size * 3);
	outerAthmosphere = new Particle(position, { 0, 0, 0 }, { 0, 0, 1, 0.2 }, size * 5);

	planetGravity = new TornadoForceGenerator(position, size * 5, 0.5, { 0, 0, 1 }, size * 3, 9.8);
	ForceSystem* forSys = new ForceSystem();
	forSys->addForceGenerator(planetGravity);
	mScene->addForceSistem(forSys);
}

Planet::~Planet()
{
	delete planetBody;
	//delete innerAthmosphere;
	delete outerAthmosphere;
}

void Planet::setActive(bool act)
{
	planetBody->setActive(act);
	//innerAthmosphere->setActive(act);
	outerAthmosphere->setActive(act);
	planetGravity->setActive(act);
}