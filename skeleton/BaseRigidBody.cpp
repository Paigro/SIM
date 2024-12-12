#include "BaseRigidBody.h"


BaseRigidBody::BaseRigidBody(PxPhysics* physics)
	:gPhysics(physics)
{

}

BaseRigidBody::~BaseRigidBody()
{
	DeregisterRenderItem(renderItem);
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

bool BaseRigidBody::update(float t)
{
	if (!isActive) { return true; } // Si no esta activa no se hace lo de abajo.
	if (outOfTime(t)) { isAlive = false; } // Calcula si esta fuera de tiempo o de espacio.
	if (!isAlive) { return false; } // Comunicarle a la escena que la tiene que eliminar.

	return true;
}

bool BaseRigidBody::outOfTime(float t)
{
	if (!canDieByTime) { return false; }
	timeAlive += t;
	if (timeAlive > lifeTime)
	{
		//std::cout << "//--MENSAJE: RigidBody out of time." << std::endl;
		timeAlive = 0;
		return true;
	}
	return false;
}

void BaseRigidBody::setPose(PxTransform newPose)
{
	pose = newPose;
}

void BaseRigidBody::setLifeTime(float _tim)
{
	lifeTime = _tim;
	if (lifeTime < 0)
	{
		canDieByTime = false;
		std::cout << "//----AVISO: RigidBody tiene tiempo infinito y no puede morir." << std::endl;
	}
}

void BaseRigidBody::addLiveToParticle(float addedTime)
{
	lifeTime = timeAlive + addedTime;
}