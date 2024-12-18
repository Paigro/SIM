#include "ExplosionForceGenerator.h"

ExplosionForceGenerator::ExplosionForceGenerator(Vector3 pos, float rad, float vel, float _k, float _tau)
	: ForceGenerator(pos, rad), expansionVel(vel), k(_k), tau(_tau)
{
	timePassed = 0;
	std::cout << "//--MENSAJE: Nuevo generador de EXPLOSION." << std::endl;
}

void ExplosionForceGenerator::updateFGen(float t)
{
	if (timePassed <= 4 * tau)
	{
		timePassed += t;
		setRadius(expansionVel * timePassed);
	}
}

Vector3 ExplosionForceGenerator::generateForce(Vector3 objPos, Vector3 objVel, float objSize)
{
	Vector3 force(0, 0, 0);

	if (timePassed < 0 || timePassed >= 4 * tau)
	{
		return force;
	}

	float dis = (objPos - position).magnitude(); // Distancia del centro a la particula.

	if (dis >= radius)
	{
		return force;
	}

	force = ((k / dis * dis) * (objPos - position)) * exp(-timePassed / tau);

	return force;
}

void ExplosionForceGenerator::resetExplosion()
{
	radius = 0;
	timePassed = 0;
}