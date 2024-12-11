#include "BaseRigidBody.h"


BaseRigidBody::BaseRigidBody(PxPhysics* gPhysics)
{
	//renderItem = new RenderItem(shape, &pose, color);
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