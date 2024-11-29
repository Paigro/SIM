#pragma once

#include <PxPhysicsAPI.h>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"


class Particle
{
private:

	//------Posicion y lo que le afecta:

	physx::PxTransform pose; // Posicion de la particula. La pose tiene un Vector3 p y un cuaternion q.

	Vector3 vel; // Velocidad de la particula.
	Vector3 acc; // Acceleracion de la particula.
	Vector3 accF; // Fuerzas acumuladas en un momento. Se tiene que borrar en cada ciclo del motor.
	Vector3 gravity = { 0.0, -9.8, 0.0 }; // Gravedad que le afecta a la particula.

	Vector4 color; // Color de la particula.

	float damping = 0.5; // Damping para que la velocidad no crezca excesivamente.
	float mass = 1; // Masa de la particula.
	float size; // tamanyo de la particula.

	bool gravitable = true; // Si al gravedad le afecta o no.
	bool movible = true; // Si se puede mover o no.


	//------Render Item:

	RenderItem* renderItem; // RenderItem de la particula.


	//------Vida de la particula:

	bool isActive = true; // Si la particula esta en una escena activa entonces estara a true, sino a false;
	bool canDieByTime; // Si la particula puede morir por tiempo.
	bool isAlive = true; // Dice si la particula esta viva o muerta para eliminarse o no.
	float lifeTime = 10.0; // Tiempo que va a vivir.
	float timeAlive = 0.0; // Tiempo que lleva vivo. Por defeto 10s.

public:

	//------Constructoras y destructoras:

	// Constructora de Particle con posicion, velocidad, color y tamanyo.
	Particle(Vector3 _pos, Vector3 _vel, Vector4 _col = Vector4(1, 0.5, 0, 1), float _siz = 1);
	// Constructora de Particle con posicion, velocidad, acceleracion, dumping, color y tamanyo.
	Particle(Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam, Vector4 _col, float _siz);
	// Constructora de Particle con posicion, velocidad, acceleracion, dumping, color, tamanyo y masa.
	Particle(Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam, Vector4 _col, float _siz, float mss);
	// Destructora de Particle.
	~Particle();


	//------Getters y setters:

	// Devuelve el pose.
	physx::PxTransform getPose() const { return pose; }
	// Devuelve la velocidad.
	Vector3 getVel() const { return vel; }
	// Devuelve la posicion (Vector3).
	Vector3 getPos() const { return pose.p; }
	// Devuelve la aceleracion.
	Vector3 getAcc() const { return acc; }
	// Devuelve el dumping.
	float getDamping() const noexcept { return damping; }
	// Devuelve la masa.
	float getMass() const noexcept { return mass; }
	// Devuelve si le afecta la gravedad.
	bool getGravitable() const noexcept { return gravitable; }
	// Devuelve si es movible.
	bool getMovible() const noexcept { return movible; }
	// Devuelve el tamanyo de la particula.
	float getSize() const noexcept { return size; }
	// Devuelve el tamanyo de la particula.
	Vector4 getColor() const { return color; }
	//------------------------------------------//
	// Settea el pose.
	void setPose(physx::PxTransform newPose);
	// Settea la velocidad.
	void setVel(Vector3 newVel);
	// Settea la posicion (Vector3).
	void setPos(Vector3 NewPos);
	// Settea la aceleracion.
	void setAcc(Vector3 newAcc);
	// Settea el dumping.
	void setDamping(float newDamp);
	// Settea el color de la particula.
	void setColor(float newR, float newG, float newB, float newA);
	// Settea la masa.
	void setMass(float newMss);
	// Settea si le afecta la gravedad.
	void setGravitable(bool grav);
	//Settea si se puede mover o no.
	void setMovible(bool mov);
	// Settea el tiempo maxima de vida.
	void setLifeTime(float t);
	// le mete mas tiempo a la particula (Tque ha pasado + AddedTime).
	void addLiveToParticle(float addedTime);


	//------Cambios importantes a la particula:

	// Cambia la gravedad que le afecta.
	void changeGravity(Vector3 newGrav);
	// Cambia la forma de la particula.
	void changeShape(physx::PxShape* newShape);


	//------Metodos de la particula:

	// Update de Particle.
	virtual bool update(float t);
	// Para saber si ya se ha pasado de tiempo de vida.
	bool outOfTime(float t);
	// Settea si la particula esta activa o no.
	void setActive(bool act);


	//------Metodos de movimiento:

	// Integrate con Euler normal.
	void integrateEuler(float t);
	// Integrate con Eules semiimplicito.
	void integrateEulerSemiImplicit(float t);


	//------Metodos de fuerzas:

	// Mete una fuerza a la fuerza acumulada.
	void addForce(Vector3 force);
	// Aplica las fuerzas hasta el momento acumuladas.
	void applyForce();
	// Elimina las fuerzas acumuladas.
	void clearForce();
};