#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(Particle* pRef, Vector3 iPos, Vector3 iVel, int nPar)
	: particleRef(pRef), initPos(iPos), initVel(iVel), nParticles(nPar)
{

}

ParticleSystem::~ParticleSystem()
{
	delete particleRef;
	particleRef = nullptr;
}

void ParticleSystem::update(float t)
{
	for (auto p : vParticles)
	{
		p->update(t);
	}
	if ()
	{

	}
}

void ParticleSystem::generateParticles()
{

}
