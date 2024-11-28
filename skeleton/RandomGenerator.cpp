#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(Vector3 ori, Vector3 vel, int nPar, float minT, float maxT, float minP, float maxP)
	: ParticleGenerator(ori, vel, nPar), minTimeToLive(minT), maxTimeToLive(maxT), minPos(minP), maxPos(maxP)
{



}

RandomGenerator::~RandomGenerator()
{



}

std::vector<Projectile*> RandomGenerator::CreateParticles(int actP, int maxP)
{
	std::vector<Projectile*> auxProjectictiles; // Vector para guardar las particulas generadas y despues devolverlas.

	int avaliblePar = maxP - actP; // Aprticulas que por rango se pueden generar pero que luego no tienen que generarse este numero exacto.

	//----Distribuciones:

	std::uniform_int_distribution<int> uDistribution(0, 5); // PAIGRO AQUI: ganyanada para que salga pumm...pum... y salga mas continuo.
	std::uniform_int_distribution<int> uDistributionToTime(minTimeToLive, maxTimeToLive); // Distribucion normal entre minT y maxT para el tiempo que va a vivir cada particula. Por alguna razon no puedce ser float.
	std::normal_distribution<float> uPosDistribution(minPos, maxPos); // Distribucion uniforme para la nueva posicion de la particula.

	int parToGen = uDistribution(randomGenerator); // Particulas a generar en este momento.
	int newTime = uDistributionToTime(randomGenerator); // Tiempo que va a estar viva la particula.


	float newX = 0; // Para la nueva velocidad en x.
	float newY = 0; // Para la nueva velocidad en y.
	float newZ = 0; // Para la nueva velocidad en z.

	for (int i = 0; i < parToGen; i++)
	{
		newX = uPosDistribution(randomGenerator);
		newY = uPosDistribution(randomGenerator);
		newZ = uPosDistribution(randomGenerator);

		Vector3 newPos{ newX, newY, newZ }; // Nueva posicion de la particula.

		// Nueva particulas con la posicion inicial, la nueva velocidad, la acceleracion que es inservible, damping y la gravedad en y = -10 porque asi dice el enunciado.
		Projectile* p = new Projectile(newPos, medVel, { 0, 0.5, 0 }, 0.98, 1.0, Vector4{ 1.0, 1.0, 1.0, 1.0 }, 2);
		p->setLifeTime(newTime);
		auxProjectictiles.push_back(p);
	}

	return auxProjectictiles;
}