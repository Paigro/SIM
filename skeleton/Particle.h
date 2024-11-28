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
	Vector3 initPos; // Posicion inicial de la particula para calcular su espacio vital si es necesario.
	Vector3 vel; // Velocidad de la particula.
	Vector3 acc; // Acceleracion de la particula.
	float damping = 0.5; // Damping para que la velocidad no crezca excesivamente.
	float mass = 1; // Masa de la particula.
	Vector3 accF; // Fuerzas acumuladas en un momento. Se tiene que borrar en cada ciclo del motor.
	Vector3 gravity = { 0.0, -9.8, 0.0 };
	bool gravitable = true;
	bool movible = true;


	//------Render Item:

	RenderItem* renderItem; // RenderItem de la particula.


	//------Vida de la particula:

	bool isActive = true; // Si la particula esta en una escena activa entonces estara a true, sino a false;
	bool canDieByTime; // Si la particula puede morir por tiempo.
	bool canDieBySpace; // Si la particula puede morir por espacio donde se este.
	bool isAlive = true; // Dice si la particula esta viva o muerta para eliminarse o no.
	float lifeTime = 10.0; // Tiempo que va a vivir.
	float timeAlive = 0.0; // Tiempo que lleva vivo. Por defeto 10s.
	Vector3 spaceToLive = { 100.0, 100.0, 100.0 }; // Cubo en el que puede estar las particulas. Por defecto (100.0, 100.0, 100.0).

#pragma region mensaje
	//--------------------------------------------------------------------------------------------------------------------------------------------------//
	//--------------------------------------------------------------------------------------------------------------------------------------------------//
	//--------------------------------------------------------------------------------------------------------------------------------------------------//
	// PAIGRO AQUI: meter un metodo que sea dieFor(bool byTime, bool byPos), que por defecto se pueda morir por tiempo pero que se pueda elegir, etc... //
	//--------------------------------------------------------------------------------------------------------------------------------------------------//
	//--------------------------------------------------------------------------------------------------------------------------------------------------//
	//--------------------------------------------------------------------------------------------------------------------------------------------------//
#pragma endregion

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
	physx::PxTransform getPose() { return pose; }
	// Devuelve la velocidad.
	Vector3 getVel() const { return vel; }
	// Devuelve la posicion (Vector3).
	Vector3 getPos() const { return pose.p; }
	// Devuelve la aceleracion.
	Vector3 getAcc() const { return acc; }
	// Devuelve el dumping.
	float getDamping() const { return damping; }
	// Devuelve la masa.
	float getMass()const { return mass; }
	// Devuelve si le afecta la gravedad.
	bool getGravitable() { return gravitable; }
	// Devuelve si es movible.
	bool getMovivle() { return movible; }
	// Settea el pose.
	void setPose(physx::PxTransform newPose);
	// Settea la velocidad.
	void setVel(Vector3 _vel);
	// Settea la posicion (Vector3).
	void setPos(Vector3 _pos);
	// Settea la aceleracion.
	void setAcc(Vector3 _acc);
	// Settea el dumping.
	void setDamping(float _dam);
	// Settea el color de la particula.
	void setColor(float _r, float _g, float _b, float _a);
	// Settea la masa.
	void setMass(float mss);
	// Settea si le afecta la gravedad.
	void setGravitable(bool grav);
	//Settea si se puede mover o no.
	void setMovible(bool mov);
	// Settea el tiempo maxima de vida.
	void setLifeTime(float t);
	// Settea el espacio vital de la particula.
	void setSpaceToLive(Vector3 _spa);
	// Settea como puede morir una particula. Por defecto es por tiempo.
	// Si se pasan dos false se deja como por defecto a true el de tiempo.
	// En proceso
	void setHowToDie(bool byTime, bool bySpace);


	//------Metodos de la particula.

	// Update de Particle.
	virtual bool update(float t);
	// Para saber si esta fuera de una region. Provisional
	bool outOfBounds();
	// Para saber si ya se ha pasado de tiempo de vida.
	bool outOfTime(float t);
	// Settea si la particula esta activa o no.
	void setActive(bool act);


	//------Metodos de movimiento:

	// Integrate con Euler normal.
	void integrateEuler(float t);
	void integrateEulerSemiImplicit(float t);


	//------Metodos de fuerzas:

	// Mete una fuerza a la fuerza acumulada.
	void addForce(Vector3 force);
	// Aplica las fuerzas hasta el momento acumuladas.
	void applyForce();
	// Elimina las fuerzas acumuladas.
	void clearForce();
};