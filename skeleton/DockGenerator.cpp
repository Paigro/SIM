#include "DockGenerator.h"


DockGenerator::DockGenerator(Vector3 ori, Vector3 vel, int nPar, float minT, float maxT)
	: ParticleGenerator(ori, vel, nPar), minTimeToLive(minT), maxTimeToLive(maxT)
{

}

DockGenerator::~DockGenerator()
{

}

std::vector<Projectile*> DockGenerator::CreateParticles(int actP, int maxP)
{
	std::vector<Projectile*> auxProjectictiles; // Vector para guardar las particulas generadas y despues devolverlas.

	Particle* part = new Particle(Vector3(50, 50, 50), Vector3(0, 0, 0));
	part->setMass(4);

	part->setLifeTime(100);

	return auxProjectictiles;
}

std::vector<Particle*> DockGenerator::CreateParticles()
{
	std::vector<Particle*> auxProjectictiles; // Vector para guardar las particulas generadas y despues devolverlas.

	Projectile* proj = new Projectile(Vector3(50, 50, 50), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, 4, Vector4(1, 0.5, 0, 1), 2);
	AnchorForceGenerator* anchor = new AnchorForceGenerator(Vector3(50, 25, 50), 1, 20, Vector3(50, 40, 50));

	auxProjectictiles.push_back(proj);

	return auxProjectictiles;
}