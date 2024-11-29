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

Vector3 ExplosionForceGenerator::generateForce(Particle& par)
{
	Vector3 force(0, 0, 0);
	Vector3 parPos = par.getPos();

	if (timePassed < 0 || timePassed >= 4 * tau)
	{
		return force;
	}

	float dis = (parPos - position).magnitude(); // Distancia del centro a la particula.

	if (dis >= radius)
	{
		return force;
	}

	force = ((k / dis * dis) * (parPos - position)) * exp(-timePassed / tau);

	return force;
}

void ExplosionForceGenerator::resetExplosion()
{
	timePassed = 0;
}