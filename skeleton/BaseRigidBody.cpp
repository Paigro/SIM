#include "BaseRigidBody.h"


BaseRigidBody::BaseRigidBody(PxPhysics* physics)
	:gPhysics(physics)
{

}

BaseRigidBody::~BaseRigidBody()
{

}

void BaseRigidBody::setActive(bool act)
{
	isActive = act;

	if (act)
	{
		RegisterRenderItem(renderItem);
	}
	else
	{
		DeregisterRenderItem(renderItem);
	}
}

void BaseRigidBody::setPose(PxTransform newPose)
{
	pose = newPose;
}