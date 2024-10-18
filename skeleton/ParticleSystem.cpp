#include "ParticleSystem.h"

#include <iostream>

ParticleSystem::ParticleSystem(Particle* pRef, Vector3 iPos, Vector3 iVel, int nPar)
	: particleRef(pRef), initPos(iPos), initVel(iVel), nParticles(nPar)
{
	timeToAppear = 1.0;
	timerToAppear = 0.0;
	vParticles.push_back(particleRef);
}

ParticleSystem::~ParticleSystem()
{
	delete particleRef;
	particleRef = nullptr;
}

void ParticleSystem::update(float t)
{
	// Gestion de las particulas. PAIGRO AQUI.
	for (auto it = vParticles.begin(); it != vParticles.end();)
	{
		Particle* p = *it;
		if (!p->update(t))
		{
			delete p;
			it = vParticles.erase(it);
		}
		else
		{
			++it;
		}
	}
	if (timerToAppear >= timeToAppear)
	{
		timerToAppear = 0;
		//for (auto p : vParticles)
		//{
			//if (p != nullptr)
			//{
		generateParticles(particleRef->getPos());
		//}
	//}
	}
	else
	{
		timerToAppear += t;
	}
}

void ParticleSystem::generateParticles(Vector3 _pos)
{
	std::cout << "GENERA" << std::endl;
	if (vParticles.size() < nParticles - 1)
	{
		vParticles.push_back(new Particle(_pos, initVel * 2, particleRef->getAcc(), particleRef->getDamping()));
	}
}
