#include "BandForceGenerator.h"


BandForceGenerator::BandForceGenerator(Vector3 pos, float rad, float _k, float rest, Particle* p1, Particle* p2)
	: ForceGenerator(p1->getPos(), rad), k(_k), restingLength(rest), part1(p1), part2(p2)
{
	std::cout << "//--MENSAJE: Nuevo generador de GOMA." << std::endl;
}

BandForceGenerator::~BandForceGenerator()
{
	//delete part1;
	//delete part2;
}

Vector3 BandForceGenerator::generateForce(Particle& par)
{
	Vector3 force(0, 0, 0);
	Vector3 part1Pos = part1->getPos();
	Vector3 part2Pos = par.getPos();

	// Longitud actual, deformaremos dependiendo de esto.
	Vector3 dir = part1Pos - part2Pos; // Obtenemos la direccion entre las particulas.
	float lenght = dir.magnitude(); // Hacemos su modulo y sacamos la distancia.
	dir.normalize(); // Normalizamos la direccion.

	// Muelle:
	float diff = lenght - restingLength; // Diferencia entre la logitud de reposo y la actual
	if (diff <= 0) // Si la diferencia es menor a la de reposo (la diff es menor que 0) entonces la goma no tiene deformacion.
	{
		diff = 0;
	}

	force = dir * k * diff; // Calculamos la fuerza.
	part1->addForce(-force); // La otra particula tambien tiene que cambiar su fuerza.

	// PAIGRO AQUI: por alguna razon se genera fuerza en y que contrarresta a la de ala gravedad entonces se quedan en diagonal.
	return force;
}

bool BandForceGenerator::isOnRadius(Particle* part)
{
	return part == part2;
}
