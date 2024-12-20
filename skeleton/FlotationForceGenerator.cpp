#include "FlotationForceGenerator.h"

FlotationForceGenerator::FlotationForceGenerator(float den, float hei)
	: ForceGenerator(Vector3(0, hei, 0)), density(den), height(hei)
{
	std::cout << "//--MENSAJE: Nuevo generador de FLOTACION." << std::endl;
}

FlotationForceGenerator::~FlotationForceGenerator()
{

}

Vector3 FlotationForceGenerator::generateForce(Particle& par)
{
	Vector3 force(0, 0, 0);
	Vector3 parPos = par.getPos(); // Posicion de la particula.
	float parHeight = par.getSize() * 2; // Altura de la particula. Radio * 2.
	float parH = parPos.y; // La altura de la particula
	float inmersed = 0; // Porcentaje de la particula sumergida.
	float volume = pow(parHeight, 3); // Volumne de la particula.

	// 0,5 porque asi viene dado.
	if ((parHeight - height) > (parHeight * 0.5)) // Cuando no esta sumergido.
	{
		inmersed = 0.0;
	}
	else if ((height - parHeight) > (parHeight * 0.5)) // Cuando esta totalmente sumergido.
	{
		inmersed = 1.0;
	}
	else  // Cuando esta particalmente sumergido.
	{
		inmersed = (height - parH) / (parHeight + 0.5);
	}

	// Calcula de la fuerza.
	force.y = density * volume * inmersed * 9.8; // Formula f = p * V * frac_sum * g

	return force;
}

bool FlotationForceGenerator::isOnRadius(Particle* part)
{
	return part->getPos().y <= height; // Solo esta "en el radio" si su algura es menor a la que hemos puesto que este el liquido.
}
