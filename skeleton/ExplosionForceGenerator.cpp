#include "ExplosionForceGenerator.h"

ExplosionForceGenerator::ExplosionForceGenerator(Vector3 pos, float rad, float vel, float pow)
	: ForceGenerator(pos, rad), expansionVel(vel), k(pow)
{
	timePassed = 0;
	tau = 0.05;
	std::cout << "//--MENSAJE: nuevo generador de explosion." << std::endl;
}

void ExplosionForceGenerator::updateFGen(float t)
{
	if (timePassed <= 10)
	{
		timePassed += t;
		setRadius(expansionVel * timePassed);
		std::cout << expansionVel * timePassed << std::endl;
	}
}

Vector3 ExplosionForceGenerator::generateForce(Particle& par)
{
	Vector3 force(0, 0, 0);
	Vector3 parPos = par.getPos();

	if (timePassed < 0 || timePassed >= 10)
	{
		return force;
	}

	float dis = (parPos - position).magnitude(); // Distancia del centro a la particula.

	if (dis <= radius)
	{
		return force;
	}

	force = ((k / dis * dis) * (parPos - position)) * exp(-timePassed / tau);

	return Vector3();
}

void ExplosionForceGenerator::resetExplosion()
{
	timePassed = 0;
}