#include "FireworkGenerator.h"

#include <random>	


FireworkGenerator::FireworkGenerator(Vector3 ori, Vector3 vel, int nPar, float minT, float maxT, float yOff)
	: ParticleGenerator(ori, vel, nPar), minTimeToLive(minT), maxTimeToLive(maxT), yOffset(yOff)
{
	shootParticle = new Projectile(initPos, medVel, { 0, 10, 0 }, 1.0, 1.0, { 0, 10, 0 }, { 1.0, 0.0, 0.0, 1.0 }, 1);
	shootParticle->setLifeTime(1.5);
	shot = false;
}

FireworkGenerator::~FireworkGenerator()
{

}

std::vector<Projectile*> FireworkGenerator::CreateParticles(int actP, int maxP)
{
	std::vector<Projectile*> auxProjectictiles; // Vector para guardar las particulas generadas y despues devolverlas.
	if (!shot)
	{
		auxProjectictiles.push_back(shootParticle);
		shot = true;
	}
	//std::cout << shootParticle->getPos().y << " " << initPos.y + yOffset << std::endl;
	if (shootParticle != nullptr && shootParticle->getPos().y >= (initPos.y + yOffset))
	{
		int avaliblePar = maxP - actP; // Aprticulas que por rango se pueden generar pero que luego no tienen que generarse este numero exacto.

		//----Distribuciones:

		std::uniform_int_distribution<int> uDistributionToTime(minTimeToLive, maxTimeToLive); // Distribucion normal entre minT y maxT para el tiempo que va a vivir cada particula. Por alguna razon no puedce ser float.
		std::uniform_int_distribution<int> uDistributionToColor(0, 1);
		std::normal_distribution<float> nDistribution(10.0, 0.5); // Distribucion normal para la generacion de nuevas velocidades de las nuevas particulas. Siendo el primer parametro lo lejos que van y el segundo la dispersion.
		std::binomial_distribution<int> bDistribution(100, 0.1); // Distribucion binomial para la velocidad.

		int newTime = uDistributionToTime(randomGenerator); // Tiempo que va a estar viva la particula.

		float newR; // Para la R del nuevo color.
		float newG; // Para la G del nuevo color.
		float newB; // Para la B del nuevo color.

		float newX = 0; // Para la nueva velocidad en x.
		float newY = 0; // Para la nueva velocidad en y.
		float newZ = 0; // Para la nueva velocidad en z.

		for (int i = 0; i < avaliblePar; i++)
		{
			newX = bDistribution(randomGenerator);
			newY = bDistribution(randomGenerator);
			newZ = bDistribution(randomGenerator);

			newR = uDistributionToColor(randomGenerator);
			newG = uDistributionToColor(randomGenerator);
			newB = uDistributionToColor(randomGenerator);

			Vector3 newVel{ newX, newY, newZ }; // Nueva velocidad de la particula.

			// Nueva particulas con la posicion inicial, la nueva velocidad, la acceleracion que es inservible, damping y la gravedad en y = -10 porque asi dice el enunciado.
			Projectile* p = new Projectile(initPos + Vector3{ 0.0, yOffset, 0.0 }, newVel, { 0, -10, 0 }, 1.0, 1.0, { 0, -10, 0 }, Vector4{ newR, newG, newB, 1.0 }, 1);
			p->setLifeTime(newTime);
			auxProjectictiles.push_back(p);
		}
	}

	return auxProjectictiles;
}