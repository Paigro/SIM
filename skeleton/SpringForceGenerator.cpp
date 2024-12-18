#include "SpringForceGenerator.h"


SpringForceGenerator::SpringForceGenerator(Vector3 pos, double _k, double _restLenght, Particle* _otherP)
	: ForceGenerator(pos), k(_k), restingLength(_restLenght), otherPart(_otherP)
{
	std::cout << "//--MENSAJE: Nuevo generador de MUELLE." << std::endl;
}

Vector3 SpringForceGenerator::generateForce(Vector3 objPos, Vector3 objVel, float objSize)
{
	Vector3 force(0, 0, 0);
	Vector3 otherPartPos = otherPart->getPos();

	Vector3 relativePos = otherPartPos - objPos;

	// Normalizar.
	const float lenght = relativePos.normalize();
	const float deltaX = lenght - restingLength;

	force = relativePos * deltaX * k;

	return force;
}