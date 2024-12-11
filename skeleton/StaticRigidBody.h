#pragma once

#include "BaseRigidBody.h"


class StaticRigidBody : public BaseRigidBody
{
private:

	PxRigidStatic* actor; // Referencia al actor estatico.

public:

	//------Constructoras y destructoras:

	// Constructora base de StaticRigidBody.
	StaticRigidBody(PxPhysics* physics, PxScene* scene, PxTransform initPose, PxShape* initShape, Vector4 initColor, Vector3 initSize);
	// Destructora de StaticRigidBody.
	~StaticRigidBody();


	//------Metodos heredados:

	// Update de StaticRigidBody.
	bool update(float t) override;
	// Settea si el rigid body esta activo o no.
	virtual void setActive(bool act);


	//------Getters y setters:

	// Devuelve la pose del rigid body.
	PxTransform getPose() const override { return actor->getGlobalPose(); }
	// Devuelve el actor.
	PxRigidActor* getActor() const { return actor; }
	//------------------------------------------------------------// 
	// Settea la pose.
	void setPose(PxTransform newPose) override;
	// Settea una nueva forma.
	virtual void setShape(PxShape* newShape, Vector3 newSize);
};