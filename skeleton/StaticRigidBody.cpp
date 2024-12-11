#include "StaticRigidBody.h"

StaticRigidBody::StaticRigidBody(PxPhysics* gPhysics, PxScene* scene, PxTransform initPose, PxShape* initShape, Vector4 initColor, Vector3 initSize)
	: BaseRigidBody(gPhysics)
{
	pose = initPose;
	shape = initShape;
	color = initColor;
	size = initSize;
	gScene = scene;

	actor = gPhysics->createRigidStatic(pose);
	actor->attachShape(*shape);

	gScene->addActor(*actor);

	renderItem = new RenderItem(shape, actor, color);
}

StaticRigidBody::~StaticRigidBody()
{

}

bool StaticRigidBody::update(float t)
{
	return true; // No hace nada el estatico.
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