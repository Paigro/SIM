#include "Particle.h"

#include <iostream>


Particle::Particle(Vector3 _pos, Vector3 _vel, Vector4 _col, float _siz)
	: pose(_pos), vel(_vel), acc(0)
{
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(_siz)), &pose, _col);
	spaceToLive = { 100.0, 100.0, 100.0 };
	lifeTime = 10.0;
	timeAlive = 0.0;
	accF = { 0, 0, 0 };
}

Particle::Particle(Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam, Vector4 _col, float _siz)
	: Particle(_pos, _vel, _col, _siz)
{
	acc = _acc;
	damping = _dam;
}

Particle::Particle(Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam, Vector4 _col, float _siz, float mss)
	: Particle(_pos, _vel, _acc, _dam, _col, _siz)
{
	mass = mss;
}

Particle::~Particle()
{

	DeregisterRenderItem(renderItem); // PAIGRO AQUI: no hace falta hacer un deregister pq delete ya lo hace pero sigue dando error. Ya no da error pero dejo la nota.
}

#pragma region sets:

void Particle::setPose(physx::PxTransform newPose)
{
	pose = newPose;
}

void Particle::setVel(Vector3 _pos)
{
	pose.p = _pos;
}

void Particle::setPos(Vector3 _vel)
{
	vel = _vel;
}

void Particle::setAcc(Vector3 _acc)
{
	acc = _acc;
}

void Particle::setDamping(float _dam)
{
	damping = _dam;
}

void Particle::setColor(float _r, float _g, float _b, float _a)
{
	renderItem->color.x = _r;
	renderItem->color.y = _g;
	renderItem->color.z = _b;
	renderItem->color.w = _a;
}

void Particle::setMass(float mss)
{
	mass = mss;
}

void Particle::setGravitable(bool grav)
{
	gravitable = grav;
}

void Particle::setLifeTime(float _tim)
{
	lifeTime = _tim;
}

void Particle::setSpaceToLive(Vector3 _spa)
{
	spaceToLive = _spa;
}

void Particle::setHowToDie(bool byTime, bool bySpace)
{
	std::cout << "//--AVISO: en proceso." << std::endl;
	// Para que no pueda no morir.
	if (byTime == false && bySpace == false)
	{
		canDieBySpace = true;
		canDieBySpace = false;
	}
	else
	{
		canDieByTime = byTime;
		canDieBySpace = bySpace;
	}
}

#pragma endregion

#pragma region update:

bool Particle::update(float t)
{
	if (!isActive) { return true; } // Si no esta activa no se hace lo de abajo.
	if (/*outOfBounds() ||*/ outOfTime(t)) { isAlive = false; } // Calcula si esta fuera de tiempo o de espacio.
	if (!isAlive) { return false; } // Comunicarle a la escena que la tiene que eliminar.

	applyForce(); // Aplicar fuerzas.

	integrateEuler(t); // Movimiento.

	clearForce(); // Eliminamos las fuerzas.

	return true;
}

#pragma endregion

#pragma region comprobaciones de muerte:

bool Particle::outOfBounds()
{
	// Para eliminar las particulas tras salir de una distancia.
	if (pose.p.x > initPos.x + spaceToLive.x || pose.p.y > initPos.y + spaceToLive.y || pose.p.z > initPos.z + spaceToLive.z ||
		pose.p.x < initPos.x - spaceToLive.x || pose.p.y < initPos.y - spaceToLive.y || pose.p.z < initPos.z - spaceToLive.z)
	{
		//std::cout << "//--MENSAJE: Particle out of bounds." << std::endl;
		return true;
	}
	return false;
}

bool Particle::outOfTime(float t)
{
	timeAlive += t;
	if (timeAlive > lifeTime)
	{
		//std::cout << "//--MENSAJE: Particle out of time." << std::endl;
		timeAlive = 0;
		return true;
	}
	return false;
}

void Particle::setActive(bool act)
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

#pragma endregion

#pragma region integradores:

void Particle::integrateEuler(float t)
{
	pose.p = pose.p + t * vel;
	vel = vel + t * acc;
	vel = vel * pow(damping, t);
}

void Particle::integrateEulerSemiImplicit(float t)
{
	vel = vel + t * acc;
	pose.p = pose.p + t * vel;
	vel = vel * pow(damping, t);
}

#pragma endregion

#pragma region gestion de fuerzas:

void Particle::addForce(Vector3 force)
{
	accF += force;
	//std::cout << "se la he metido" << std::endl;
}

void Particle::applyForce()
{
	acc = accF / mass;
	if (gravitable)
	{
		acc += gravity;
	}
}

void Particle::clearForce()
{
	accF = { 0, 0, 0 };
}

#pragma endregion