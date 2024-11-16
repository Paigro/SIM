#include "Scene.h"


Scene::Scene()
{
	initScene();
}

Scene::~Scene()
{
	for (auto* p : vParticles)
	{
		delete p;
	}
	vParticles.clear();

	for (auto* ps : vParticleSystems)
	{
		delete ps;
	}
	vParticleSystems.clear();
}

void Scene::updateScene(float t)
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

	// Gestion de los sistemas de particulas. PAIGRO AQUI.
	for (auto it = vParticleSystems.begin(); it != vParticleSystems.end();)
	{
		ParticleSystem* ps = *it;
		if (!ps->update(t))
		{
			delete ps;
			it = vParticleSystems.erase(it);
		}
		else
		{
			++it;
		}
	}

	// Gestion de los sitemas de fuerzas.
	for (auto fs : vForceSystems)
	{

		fs->addForceToParticles(vParticles, t);

		for (auto ps : vParticleSystems)
		{
			fs->addForceToParticles(ps->getVParticles(), t);
		}
		fs->update(t);
	}
}

void Scene::initScene()
{



}

void Scene::addParticle(Projectile* par)
{
	vParticles.emplace_back(par);
}

void Scene::activateScene()
{



}

void Scene::deactivateScene()
{



}

void Scene::addParticleSystem(ParticleSystem* parSys)
{
	vParticleSystems.emplace_back(parSys);
}

void Scene::addForceSistem(ForceSystem* forSys)
{
	vForceSystems.push_back(forSys);
}