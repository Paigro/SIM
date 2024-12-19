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

	Vector3 dir = objPos - position;
	float distance;

	if (tornadoAxis == Vector3(1, 0, 0)) // Tornado en el eje YZ.
	{
		distance = sqrt(dir.y * dir.y + dir.z * dir.z);

		force = k * Vector3(0, dir.z, -dir.y);
	}
	else if (tornadoAxis == Vector3(0, 1, 0)) // Tornado en el eje XZ.
	{
		distance = sqrt(dir.x * dir.x + dir.z * dir.z);

		force = k * Vector3(-dir.z, 0, dir.x);
	}
	else if (tornadoAxis == Vector3(0, 0, 1)) // Tornado en el eje XY.
	{
		distance = sqrt(dir.x * dir.x + dir.y * dir.y);

		force = k * Vector3(dir.y, -dir.x, 0);
	}
	else
	{
		std::cout << "//------ERROR: axis del tornado mal configurado." << std::endl;
	}
	force -= (dir / distance) * attraction;

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