#pragma once

#include "BaseRigidBody.h"


class DinamicRigidBody : public BaseRigidBody
{
private:

	PxRigidDynamic* actor; // Referencia al actor dinamico.

	float density; // Desnidad del rigid body.

	float mass;

	Vector3 size;

public:

	//------Constructoras y destructoras:

	// Constructora base de DinamicRigidBody.
	DinamicRigidBody(PxPhysics* gPhysics, PxScene* scene, PxTransform initPose, PxShape* initShape, Vector4 initColor, Vector3 initSize, float initDensity = 1.0, float initMass = 1.0);
	// Destructora de DinamicRigidBody.
	~DinamicRigidBody();


	//------Metodos heredados:

	// Update de DinamicRigidBody.
	bool update(float t) override;
	// Settea si el rigid body esta activo o no.
	virtual void setActive(bool act);


	//------Momentos de inercia:

	//
	void setTensorManually(Vector3 newTensor);


	//------Fuerzas:

	// Le da fuerza al actor.
	void addForce(Vector3 force) override;


	//------Getters y setters:

	// Devuelve la pose del rigid body.
	PxTransform getPose() const override { return actor->getGlobalPose(); }
	// Devuelve el actor.
	PxRigidActor* getActor() const { return actor; }
	// Devuelve la densidad.
	float getDensity() { return density; }
	// Devuelve la masa.
	float getMass() { return density; }
	// Devuelve la masa.
	Vector3 getSize() { return size; }
	// Devuelve la velocidad.
	Vector3 getVel() override;
	//------------------------------------------------------------//
	// Settea la pose.
	void setPose(PxTransform newPose) override;
	// Settea una nueva forma.
	virtual void setShape(PxShape* newShape, Vector3 newSize);
	// Settea una nueva densidad.
	void setDensity(float newDensity);
};