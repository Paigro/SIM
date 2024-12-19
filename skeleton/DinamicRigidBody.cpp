#include "DinamicRigidBody.h"


DinamicRigidBody::DinamicRigidBody(PxPhysics* gPhysics, PxScene* scene, PxTransform initPose, PxShape* initShape, Vector4 initColor, Vector3 initSize, float initDensity)
	: BaseRigidBody(gPhysics,initSize)
{
	pose = initPose;
	shape = initShape;
	color = initColor;
	gScene = scene;
	density = initDensity;

	actor = gPhysics->createRigidDynamic(pose);
	actor->setLinearVelocity({ 0,0,0 });
	actor->setAngularVelocity({ 0,0,0 });
	PxRigidBodyExt::updateMassAndInertia(*actor, density);
	actor->attachShape(*shape);

	gScene->addActor(*actor);

	renderItem = new RenderItem(shape, actor, color);
}

DinamicRigidBody::~DinamicRigidBody()
{
	actor->release();
	//BaseRigidBody::~BaseRigidBody();
}

bool DinamicRigidBody::update(float t)
{
	return BaseRigidBody::update(t);
}

void DinamicRigidBody::setActive(bool act)
{
	BaseRigidBody::setActive(act);

	if (act)
	{
		gScene->addActor(*actor);
	}
	else
	{
		gScene->removeActor(*actor);
	}
}

void DinamicRigidBody::addForce(Vector3 force)
{
	actor->addForce(force);
}

Vector3 DinamicRigidBody::getVel()
{
	return actor->getLinearVelocity();
}

void DinamicRigidBody::setPose(PxTransform newPose)
{
	actor->setGlobalPose(newPose);
}

void DinamicRigidBody::setShape(PxShape* newShape, Vector3 newSize)
{
	shape->release();
	shape = newShape;
	size = newSize;

	actor->attachShape(*shape);
}

void DinamicRigidBody::setDensity(float newDensity)
{
	density = newDensity;
}