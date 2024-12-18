#include "WindForceGenerator.h"

WindForceGenerator::WindForceGenerator(Vector3 pos, float rad, Vector3 vel, float _k1, Vector3 _k2)
	: ForceGenerator(pos, rad), windVel(vel), k1(_k1), k2(_k2)
{
	std::cout << "//--MENSAJE: Nuevo generador de VIENTO." << std::endl;
}

Vector3 WindForceGenerator::generateForce(Vector3 objPos, Vector3 objVel, float objSize)
{
	Vector3 force(0, 0, 0);

	if (isActive)
	{
		Vector3 parVel = objVel;

		force = k1 * (windVel - parVel) + k2;
	}

	return force;
}

void WindForceGenerator::setActive(bool act)
{
	isActive = act;
}