#pragma once

#include "ForceGenerator.h"


class ExplosionForceGenerator : public ForceGenerator
{
private:

	float k; // Intensiad de la explosion.
	float tau; // Constante de tiempo.
	float expansionVel; // Velocidad de expasion de la explosion.

	float timePassed; // Tiempo que ha pasado desde que ha empezado la explosion.

public:

	//------Constructoras y destructoras:

	// Constructora de ExplosionForceGenerator base con posicion inicial, radio, velocidad de expansion e intensidad de la explosion.
	ExplosionForceGenerator(Vector3 pos, float rad, float vel, float _k, float _tau = 2);
	// Desctructora de ExplosionForceGenerator.
	~ExplosionForceGenerator() {};


	//------Metodos heredados:

	// Update de ExplosionForceGenerator.
	void updateFGen(float t);
	// Genera la fuerza del viento.
	Vector3 generateForce(Particle& par) override;


	//------Metodos de la explosion:

	// Resetea la explosion.
	void resetExplosion();
};