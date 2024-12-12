#pragma once

#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

#include <iostream>
#include <queue>

#include "DinamicRigidBody.h"


using namespace physx;


class Canon
{
private:

	std::queue<DinamicRigidBody*> qRigidBodies; // Cola de rigidBodies que dispara el canon.




public:

	//------Constructoras y destructoras:

	// Constructora de Canon con numero de objetos que va a lanzar.
	Canon(int projectiles);
	// Destructora de Canon.
	~Canon();


	//------Disparo del canon:

	// El disparo devuelve el riggibBody que a lanzado, lo elimina de su cola para que lo gestione la escena.
	DinamicRigidBody* shoot();

};