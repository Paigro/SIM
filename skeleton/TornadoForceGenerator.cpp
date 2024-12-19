#include "TornadoForceGenerator.h"

TornadoForceGenerator::TornadoForceGenerator(Vector3 pos, float rad, float _k, Vector3 axis, float inRadius, float attractionCte)
	:ForceGenerator(pos, rad), k(_k), tornadoAxis(axis), innerRadius(inRadius), attraction(attractionCte * 2)
{
	std::cout << "//--MENSAJE: Nuevo generador de TORNADO." << std::endl;
}

Vector3 TornadoForceGenerator::generateForce(Vector3 objPos, Vector3 objVel, float objSize)
{
	Vector3 force(0, 0, 0);

	if (!isActive) { return force; }

	Vector3 relativePos = objPos - position;
	float distance;

	if (tornadoAxis == Vector3(1, 0, 0)) // Tornado en el eje YZ.
	{
		distance = sqrt(relativePos.y * relativePos.y + relativePos.z * relativePos.z);

		force = k * Vector3(0, relativePos.z, -relativePos.y);
	}
	else if (tornadoAxis == Vector3(0, 1, 0)) // Tornado en el eje XZ.
	{
		distance = sqrt(relativePos.x * relativePos.x + relativePos.z * relativePos.z);

		force = k * Vector3(-relativePos.z, 0, relativePos.x);
	}
	else if (tornadoAxis == Vector3(0, 0, 1)) // Tornado en el eje XY.
	{
		distance = sqrt(relativePos.x * relativePos.x + relativePos.y * relativePos.y);

		force = k * Vector3(relativePos.y, -relativePos.x, 0);
	}
	else
	{
		std::cout << "//------ERROR: axis del tornado mal configurado." << std::endl;
	}
		force -= (relativePos / distance) * attraction;

	if (distance < innerRadius)
	{
		return Vector3(0, 0, 0);
	}

	force = force - objVel;

	return force;
}

void TornadoForceGenerator::setActive(bool act)
{
	isActive = act;
}