#pragma once

#include "Particle.h"


class Planet
{
private:

	Particle* planetBody;

	int athmosphere; 

public:

	//------Constructoras y destructoras:

	// Contructora base de Planet.
	Planet(Vector3 initPos,float planetSize);
	// Destructora de Planet.
	~Planet();


	//------Metodos importantes:

	// Settea si esta activo o no.
	void setActive(bool act);
};