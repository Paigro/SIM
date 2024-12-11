#pragma once

#include <PxPhysicsAPI.h>
#include "core.hpp"
#include "RenderUtils.hpp"

using namespace physx;


class BasicObject
{
private:



protected:

	//------Posicion y lo que le afecta:

	physx::PxTransform pose; // Posicion de la particula. La pose tiene un Vector3 p y un cuaternion q.

	Vector3 vel; // Velocidad de la particula.
	Vector3 acc; // Acceleracion de la particula.
	Vector3 accF; // Fuerzas acumuladas en un momento. Se tiene que borrar en cada ciclo del motor.
	Vector3 gravity = { 0.0, -9.8, 0.0 }; // Gravedad que le afecta a la particula.

	Vector4 color; // Color de la particula.

	float damping = 0.5; // Damping para que la velocidad no crezca excesivamente.
	float mass = 1; // Masa de la particula.
	float size; // Tamanyo de la particula.

	bool gravitable = true; // Si al gravedad le afecta o no.
	bool movible = true; // Si se puede mover o no.


	//------Render Item:

	RenderItem* renderItem; // RenderItem de la particula.


	//------Vida de la particula:

	bool isActive = true; // Si la particula esta en una escena activa entonces estara a true, sino a false;
	bool canDieByTime; // Si la particula puede morir por tiempo.
	bool isAlive = true; // Dice si la particula esta viva o muerta para eliminarse o no.
	float lifeTime = 10.0; // Tiempo que va a vivir. Por defeto 10s.
	float timeAlive = 0.0; // Tiempo que lleva vivo.



public:

	//------

	//
	BasicObject();
	//
	~BasicObject();


	//------

	//
	virtual bool update(float t);


	//------

	// Para activar o desactivar el objeto.
	virtual void setActive(bool act);


};