#include "TornadoForceGenerator.h"

TornadoForceGenerator::TornadoForceGenerator(Vector3 pos, float rad, float _k)
	:ForceGenerator(pos, rad), k(_k)
{
	std::cout << "//--MENSAJE: Nuevo generador de TORNADO." << std::endl;
}

Vector3 TornadoForceGenerator::generateForce(Particle& par)
{
	Vector3 force;
	Vector3 parPos = par.getPos();
	Vector3 parVel = par.getVel();

	force = k * Vector3(-(parPos.z - position.z), 50 - (parPos.y - position.y), parPos.x - position.x);

	force = force - parVel;

	return force;
}