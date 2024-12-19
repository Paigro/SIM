#include "StaticRigidBody.h"


StaticRigidBody::StaticRigidBody(PxPhysics* gPhysics, PxScene* scene, PxTransform initPose, PxShape* initShape, Vector4 initColor, Vector3 initSize)
	: BaseRigidBody(gPhysics, initSize), animos(0)
{
	pose = initPose;
	shape = initShape;
	color = initColor;
	gScene = scene;

	actor = gPhysics->createRigidStatic(pose);
	actor->attachShape(*shape);

	gScene->addActor(*actor);

	renderItem = new RenderItem(shape, actor, color);
}

StaticRigidBody::~StaticRigidBody()
{
	std::cout << "Animos conseguidos: " << animos << std::endl;

	actor->release();
	BaseRigidBody::~BaseRigidBody();
}

bool StaticRigidBody::update(float t)
{
	return BaseRigidBody::update(t);
}

void StaticRigidBody::setActive(bool act)
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

Vector3 StaticRigidBody::getVel()
{
	return Vector3(0, 0, 0);
}

void StaticRigidBody::setPose(PxTransform newPose)
{
	actor->setGlobalPose(pose);
}

void StaticRigidBody::setShape(PxShape* newShape, Vector3 newSize)
{
	shape->release();
	shape = newShape;
	size = newSize;

	actor->attachShape(*shape);
}

void StaticRigidBody::addForce(Vector3 force)
{
	animos++;
}