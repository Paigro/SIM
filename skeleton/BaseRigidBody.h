#pragma once

#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

#include <iostream>

using namespace physx;


class BaseRigidBody
{
protected:

	PxPhysics* gPhysics = nullptr; // Referencia a la fisica.
	PxScene* gScene = nullptr; // Referencia a la escena fisica.

	PxTransform pose; // Pose del rigid body.

	PxShape* shape = nullptr; // Forma del rigid body.

	Vector4 color; // Color del rigid body.

	RenderItem* renderItem = nullptr; // Referencia al renderItem del rigid body.

	Vector3 size; // Tamanyo del rigidBody.

	bool isActive = true; // Si el rigid body esta en una escena activa entonces estara a true, sino a false.
	bool canDieByTime; // Si el rigid bod puede morir por tiempo.
	bool isAlive = true; // Dice si el rigid bod esta vivo o muerto para eliminarse o no.
	float lifeTime = 10.0; // Tiempo que va a vivir. Por defeto 10s.
	float timeAlive = 0.0; // Tiempo que lleva vivo.

public:

	//------Constructoras y destructoras:

	// Constructora base de BaseRigidBody.
	BaseRigidBody(PxPhysics* physics, Vector3 initSize);
	// Destructora base de BaseRigidBody.
	virtual ~BaseRigidBody();


	//------Metodos importantes:

	// Update general.
	virtual bool update(float t);
	// Settea si el rigid body esta activo o no.
	virtual void setActive(bool act);
	// Devuelve si esta activo o no.
	bool getIsActive() { return isActive; }
	// Para saber si ya se ha pasado de tiempo de vida.
	bool outOfTime(float t);


	//------Furezas: (verdad o mentira?: sorpresa) NOTA: Necesitaba un addForce global a las dos subclases porque mis vectores son de esta clase base.

	virtual void addForce(Vector3 force) = 0;


	//------Setters y getters:

	// Devuelve la pose del rigid body.
	virtual PxTransform getPose() const { return pose; }
	// Devuelve el actor del rigid body.
	virtual PxRigidActor* getActor() const = 0;
	// Devuelve la velocidad.
	virtual Vector3 getVel() = 0;
	// Devuelve el size.
	Vector3 getSize() { return size; }
	//----------------------------------------------------------//
	// Settea la pose del rigid body.
	virtual void setPose(PxTransform pose);
	// Settea una nueva forma.
	virtual void setShape(PxShape* newShape, Vector3 newSize) = 0;
	// Settea el tiempo maxima de vida.
	void setLifeTime(float t);
	// le mete mas tiempo a la particula (Tque ha pasado + AddedTime).
	void addLiveToParticle(float addedTime);
};