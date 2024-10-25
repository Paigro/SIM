#include "FountainGenerator.h"

FountainGenerator::FountainGenerator(Vector3 ori, Vector3 vel, int nPar, float minT, float maxT)
	: ParticleGenerator(ori, vel, nPar), minTimeToLive(minT), maxTimeToLive(maxT)
{

}

FountainGenerator::~FountainGenerator()
{

}

std::vector<Projectile*> FountainGenerator::CreateParticles(int actP, int maxP)
{
	std::vector<Projectile*> auxProjectictiles;

	int avaliblePar = maxP - actP; // Aprticulas que por rango se pueden generar pero que luego no tienen que generarse este numero exacto.

	std::uniform_int_distribution<int> uDistribution(0, avaliblePar); // Distribucion uniforme entre 0 y las que se puede generar para calcular las que se generan en este momento.
	std::uniform_int_distribution<int> uDistributionToTime(minTimeToLive, maxTimeToLive); // Distribucion normal entre minT y maxT para el tiempo que va a vivir cada particula. Por alguna razon no puedce ser float.
	std::normal_distribution<float> nDistribution(10.0, 5.0); // Distribucion normal para la generacion de nuevas velocidades de las nuevas particulas.

	int parToGen = uDistribution(randomGenerator); // Particulas a generar en este momento.
	int newTime = uDistributionToTime(randomGenerator);

	float newX = 0;
	float newY = 0;
	float newZ = 0;

	for (int i = 0; i < parToGen; i++)
	{
		newX = nDistribution(randomGenerator);
		newY = nDistribution(randomGenerator);
		newZ = nDistribution(randomGenerator);

		Vector3 newVel{ newX, newY, newZ };

		// Nueva particulas con la posicion inicial, la nueva velocidad, la acceleracion que es inservible, damping y la gravedad en y = -10 porque asi dice el enunciado.
		Projectile* p = new Projectile(initPos, newVel + medVel, { 0, -10, 0 }, 1.0, 1.0, { 0,-10.0,0 }, Vector4{ 0.0, 0.0, 1.0, 1.0 }, 2);
		p->seLifeTime(newTime);
		auxProjectictiles.push_back(p);
	}


	return auxProjectictiles;
}