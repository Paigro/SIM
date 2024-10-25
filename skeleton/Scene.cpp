#include "Scene.h"


Scene::Scene()
{
	//sParticles.reserve(100);
}

Scene::~Scene()
{
	for (auto* p : sParticles)
	{
		delete p;
	}
	sParticles.clear();

	for (auto* ps : sParticleSystems)
	{
		delete ps;
	}
	sParticleSystems.clear();
}

void Scene::update(float t)
{
	// Gestion de las particulas. PAIGRO AQUI.
	for (auto it = sParticles.begin(); it != sParticles.end();)
	{
		Particle* p = *it;
		if (!p->update(t))
		{
			delete p;
			it = sParticles.erase(it);
		}
		else
		{
			++it;
		}
	}

	// Gestion de los sistemas de particulas. PAIGRO AQUI.
	for (auto it = sParticleSystems.begin(); it != sParticleSystems.end();)
	{
		ParticleSystem* ps = *it;
		if (!ps->update(t))
		{
			delete ps;
			it = sParticleSystems.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void Scene::addParticle(Particle* par)
{
	sParticles.emplace_back(par);
}

void Scene::addParticleSystem(ParticleSystem* parSys)
{
	sParticleSystems.emplace_back(parSys);
}
