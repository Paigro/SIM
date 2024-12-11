#pragma once

#include "BasicObject.h"


class BasicRigidBody : public BasicObject
{
private:



public:

	//------Constructoras y destructoras:

	// Constructora de BasicRigidBody.
	BasicRigidBody();
	// Destructora virtual de BasicRigidBody.
	virtual ~BasicRigidBody() = default;


	//------Update:

	// Update de BasicRigidBody.
	virtual bool update(float t) override;



};