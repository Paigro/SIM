#include "WindForceGenerator.h"

WindForceGenerator::WindForceGenerator(Vector3 pos, float rad, Vector3 vel)
	: ForceGenerator(pos, rad), windVel(vel)
{
	std::cout << "//--MENSAJE: nuevo generador de viento." << std::endl;
}

Vector3 WindForceGenerator::generateForce(Particle& par)
{
	Vector3 force(0, 0, 0);
	Vector3 parVel = par.getVel();

	force = k1 * (windVel - parVel) + k2;

	return force;
}