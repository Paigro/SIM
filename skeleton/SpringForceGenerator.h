#pragma once

#include "ForceGenerator.h"


class SpringForceGenerator : public ForceGenerator
{
private:

protected:

	double k; // Coeficiente de elasticidad.
	double restingLength; // Longitud en reposo.

	Particle* otherPart;

public:

	//------Constructoras y destructoras:

	// Constructora de SpringForceGenerator.
	SpringForceGenerator(Vector3 _pos, double _k, double _restLenght, Particle* _otherP);
	// Destructora de SpringForceGenerator.
	virtual ~SpringForceGenerator() {};


	//------Metodos heredados:

	// Genera la fuerza.
	Vector3 generateForce(Vector3 objPos, Vector3 objVel, float objSize) override;
	//
	void updateFGen(float t)override {}


	//------Getters y setters:

	// Settea la k.
	inline void setK(double newK) { k = newK; }
};