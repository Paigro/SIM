#pragma once

#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

using namespace physx;


class BaseRigidBody
{
protected:

	PxTransform pose; // Pose del rigid body.

	PxShape* shape = nullptr; // Forma del rigid body.

	Vector4 color; // Color del rigid body.

	RenderItem* renderItem = nullptr; // Referencia al renderItem del rigid body.

	PxScene* gScene = nullptr; // Referencia a la escena fisica.

	float size; // Tamanyo del rigidBody.

	bool isActive = true; // Si el rigid body esta en una escena activa entonces estara a true, sino a false.

public:

	//------Constructoras y destructoras:

	// Constructora base de BaseRigidBody.
	BaseRigidBody(PxPhysics* gPhysics);
	// Destructora base de BaseRigidBody.
	~BaseRigidBody();


	//------Metodos importantes:

	// Update general.
	virtual bool update(float t) = 0;
	// Settea si el rigid body esta activo o no.
	virtual void setActive(bool act);


	//------Setters y getters:

	// Devuelve la pose del rigid body.
	virtual PxTransform getPose() const { return pose; }
	// Devuelve el actor del rigid body.
	virtual PxRigidActor* getActor() const { return nullptr; }
	//----------------------------------------------------------//
	// Settea la pose del rigid body.
	virtual void setPose(PxTransform pose);
	// Settea una nueva forma.
	virtual void setShape(PxShape* newShape, float newSize) = 0;
};