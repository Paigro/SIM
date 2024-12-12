#include "Particle.h"


#pragma region constuctoras y destructoras:

Particle::Particle(Vector3 _pos, Vector3 _vel, Vector4 _col, float _siz)
	: pose(_pos), vel(_vel), acc(0), color(_col), size(_siz)
{
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(_siz)), &pose, _col);
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

#pragma endregion

#pragma region sets:

void Particle::setPose(physx::PxTransform newPose)
{
	pose = newPose;
}

void Particle::setVel(Vector3 newPos)
{
	pose.p = newPos;
}

void Particle::setPos(Vector3 newVel)
{
	vel = newVel;
}

void Particle::setAcc(Vector3 newAcc)
{
	acc = newAcc;
}

void Particle::setDamping(float newDamp)
{
	damping = newDamp;
}

void Particle::setColor(float newR, float newG, float newB, float newA)
{
	renderItem->color.x = newR;
	renderItem->color.y = newG;
	renderItem->color.z = newB;
	renderItem->color.w = newA;

	color = { newR,newG,newB,newA }; // Actualizamos el color guardado.
}

void Particle::setMass(float newMss)
{
	mass = newMss;
}

void Particle::setGravitable(bool grav)
{
	gravitable = grav;
}

void Particle::setMovible(bool mov)
{
	movible = mov;
}

void Particle::setLifeTime(float _tim)
{
	lifeTime = _tim;
	if (lifeTime < 0)
	{
		canDieByTime = false;
		std::cout << "//----AVISO: Particula tiene tiempo infinito y no puede morir." << std::endl;
	}
}

void Particle::addLiveToParticle(float addedTime)
{
	lifeTime = timeAlive + addedTime;
}

void Particle::changeGravity(Vector3 newGrav)
{
	gravity = newGrav;
}

void Particle::changeShape(physx::PxShape* newShape)
{
	if (renderItem == nullptr)
	{
		renderItem->release();
		renderItem = new RenderItem(newShape, &pose, color);
	}
	else
	{
		renderItem->shape = newShape;
	}
}

#pragma endregion

#pragma region update:

bool Particle::update(float t)
{
	if (!isActive) { return true; } // Si no esta activa no se hace lo de abajo.
	if (outOfTime(t)) { isAlive = false; } // Calcula si esta fuera de tiempo o de espacio.
	if (!isAlive) { return false; } // Comunicarle a la escena que la tiene que eliminar.
	if (!movible) { return true; } // Si no es movible no tiene que hacer nada mas.

	applyForce(); // Aplicar fuerzas.

	integrateEulerSemiImplicit(t); // Movimiento.

	clearForce(); // Eliminamos las fuerzas.

	return true;
}

#pragma endregion

#pragma region cosas importantes (gestion tiempo y setActive):

bool Particle::outOfTime(float t)
{
	if (!canDieByTime) { return false; }
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