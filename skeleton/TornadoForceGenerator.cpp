#include "TornadoForceGenerator.h"

TornadoForceGenerator::TornadoForceGenerator(Vector3 pos, float rad, float _k, Vector3 axis, float inRadius, float attractionCte)
	:ForceGenerator(pos, rad), k(_k), tornadoAxis(axis), innerRadius(inRadius), attraction(attractionCte)
{
	std::cout << "//--MENSAJE: Nuevo generador de TORNADO." << std::endl;
}

Vector3 TornadoForceGenerator::generateForce(Vector3 objPos, Vector3 objVel, float objSize)
{
	Vector3 force(0, 0, 0);

	if (!isActive) { return force; }
	int objDir;
	if ((objPos.y + objVel.y) > objPos.y)
	{
		objDir = 1;
	}
	else if ((objPos.y + objVel.y) < objPos.y)
	{
		objDir = -1;
	}
	else {
		objDir = 0;
	}

	Vector3 relativePos = objPos - position;
	float distanceToCentre;

	if (tornadoAxis == Vector3(1, 0, 0)) // Tornado en el eje YZ.
	{
		distanceToCentre = sqrt(relativePos.y * relativePos.y + relativePos.z * relativePos.z);

		force = k * Vector3(0, relativePos.z, -relativePos.y);
	}
	else if (tornadoAxis == Vector3(0, 1, 0)) // Tornado en el eje XZ.
	{
		distanceToCentre = sqrt(relativePos.x * relativePos.x + relativePos.z * relativePos.z);

		force = k * Vector3(-relativePos.z, 0, relativePos.x);
	}
	else if (tornadoAxis == Vector3(0, 0, 1)) // Tornado en el eje XY.
	{
		distanceToCentre = sqrt(relativePos.x * relativePos.x + relativePos.y * relativePos.y);

		force = k * Vector3(relativePos.y, -relativePos.x, 0);
	}
	else
	{
		std::cout << "//------ERROR: axis del tornado mal configurado." << std::endl;
	}

	force -= (relativePos / distanceToCentre) * attraction;

	if (distanceToCentre < innerRadius)
	{
		//force = -k * (relativePos / distanceToCentre);
		return force;
	}

	//force = force - (objDir * objVel);
	force = force - objVel;

	return force;
}

void TornadoForceGenerator::setActive(bool act)
{
	isActive = act;
}