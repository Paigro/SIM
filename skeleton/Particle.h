#pragma once

#include "BasicObject.h"


class Particle : public BasicObject
{
private:

	

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
	// Devuelve la posicion (Vector3).
	Vector3 getPos() const { return pose.p; }
	// Devuelve la velocidad.
	Vector3 getVel() const { return vel; }
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
	virtual bool update(float t) override;
	// Para saber si ya se ha pasado de tiempo de vida.
	bool outOfTime(float t);
	// Settea si la particula esta activa o no.
	void setActive(bool act) override;


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