#include "Planet.h"

Planet::Planet(Vector3 initPos, float planetSize)
{
	planetBody = new Particle(initPos, Vector3(0, 0, 0), Vector4(1, 1, 0, 1), planetSize);
}

Planet::~Planet()
{
	delete planetBody;
}

void Planet::setActive(bool act)
{
	planetBody->setActive(act);
}