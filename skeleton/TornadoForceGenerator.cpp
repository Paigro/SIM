#include "TornadoForceGenerator.h"

TornadoForceGenerator::TornadoForceGenerator(Vector3 pos, float rad, float _k)
	:ForceGenerator(pos, rad), k(_k)
{
	std::cout << "//--MENSAJE: Nuevo generador de TORNADO." << std::endl;
}

Vector3 TornadoForceGenerator::generateForce(Vector3 objPos, Vector3 objVel, float objSize)
{
	Vector3 force;

	force = k * Vector3(-(objPos.z - position.z), 50 - (objPos.y - position.y), objPos.x - position.x);

	force = force - objVel;

	return force;
}