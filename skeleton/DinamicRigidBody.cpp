#include "DinamicRigidBody.h"

DinamicRigidBody::DinamicRigidBody(PxPhysics* gPhysics, PxScene* scene, PxTransform initPose, PxShape* initShape, Vector4 initColor, float initSize)
	: BaseRigidBody(gPhysics)
{
	pose = initPose;
	shape = initShape;
	color = initColor;
	size = initSize;
	gScene = scene;

	actor = gPhysics->createRigidDynamic(pose);
	actor->attachShape(*shape);
	gScene->addActor(*actor);

	renderItem = new RenderItem(shape, actor, color);
}

DinamicRigidBody::~DinamicRigidBody()
{

}

bool DinamicRigidBody::update(float t)
{
	return true;
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

void DinamicRigidBody::setPose(PxTransform newPose)
{
	actor->setGlobalPose(pose);
}

void DinamicRigidBody::setShape(PxShape* newShape, float newSize)
{
	shape->release();
	shape = newShape;
	size = newSize;

	actor->attachShape(*shape);
}
