#pragma once

#include "BaseRigidBody.h"


class DinamicRigidBody : public BaseRigidBody
{
private:

	PxRigidDynamic* actor;

public:

	//------Constructoras y destructoras:

	// Constructora base de DinamicRigidBody.
	DinamicRigidBody(PxPhysics* gPhysics, PxScene* scene, PxTransform initPose, PxShape* initShape, Vector4 initColor, float initSize);
	// Destructora de DinamicRigidBody.
	~DinamicRigidBody();


	//------Metodos heredados:

	// Update de DinamicRigidBody.
	bool update(float t) override;
	// Settea si el rigid body esta activo o no.
	virtual void setActive(bool act);


	//------Fuerzas:

	void addForce(Vector3 force);


	//------Getters y setters:

	// Devuelve la pose del rigid body.
	PxTransform getPose() const override { return actor->getGlobalPose(); }
	// Devuelve el actor.
	PxRigidActor* getActor() const { return actor; }
	//------------------------------------------------------------//
	// Settea la pose.
	void setPose(PxTransform newPose) override;
	// Settea una nueva forma.
	virtual void setShape(PxShape* newShape, float newSize);
};