#include "ParticleGenerator.h"


ParticleGenerator::ParticleGenerator(Vector3 iPos, Vector3 mVel, int nPar)
	: initPos(iPos), medVel(mVel), nParticles(nPar)
{
	//orParticle = new Particle(initPos, medVel, Vector4{ 1.0, 0.5, 0.0, 0.0, }, 1);
}

ParticleGenerator::~ParticleGenerator()
{
	delete orParticle;
	orParticle = nullptr;

	for (Particle* p : vParticles)
	{
		delete p;
	}
	vParticles.clear();
}

void ParticleGenerator::setActive(bool act)
{
	/*if (act)
	{
		orParticle->setActive(true);
	}
	else
	{
		orParticle->setActive(false);
	}*/
}
