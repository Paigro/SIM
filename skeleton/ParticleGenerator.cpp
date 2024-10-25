#include "ParticleGenerator.h"


ParticleGenerator::ParticleGenerator(Vector3 iPos, Vector3 mVel, int nPar)
	: initPos(iPos), medVel(mVel), nParticles(nPar)
{
	orParticle = new Particle(initPos, medVel, Vector4{ 1.0, 0.5, 0.0, 0.0, }, 1);
}

ParticleGenerator::~ParticleGenerator()
{
	delete orParticle;
	orParticle = nullptr;

	for (Projectile* p : vProjectiles)
	{
		delete p;
	}
	vProjectiles.clear();
}
