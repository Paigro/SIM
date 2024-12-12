#pragma once

#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

#include <iostream>
#include <queue>

#include "Particle.h"
#include "StaticRigidBody.h"
#include "DinamicRigidBody.h"


using namespace physx;


class Canon
{
private:

	PxPhysics* gPhysics = nullptr; // Referencia a la fisica.
	PxScene* gScene = nullptr; // Referencia a la escena fisica.

	std::queue<DinamicRigidBody*> qRigidBodies; // Cola de rigidBodies que dispara el canon.

	Particle* canonBody; // Para que el canon se vea, es estatico porque no se va modificar.

	Vector3 position;

public:

	//------Constructoras y destructoras:

	// Constructora de Canon con numero de objetos que va a lanzar.
	Canon(PxPhysics* physics, PxScene* scene, Vector3 initPos, int projectiles);
	// Destructora de Canon.
	~Canon();


	//------Metodos importantes:

	// Settea si el canon esta activo o no.
	void setActive(bool act);


	//------Disparo del canon:

	// El disparo devuelve el riggibBody que a lanzado, lo elimina de su cola para que lo gestione la escena.
	DinamicRigidBody* shoot();


	//------Getters y setters:

	// Devuelve el numero de disparos que le quedan al canon.
	int getRemainingShoots() { return qRigidBodies.size(); }
	//-------------------------------------------------------------------//
	// Le mete mas disparos al canon.
	void addShoots(int addedShoots);


};