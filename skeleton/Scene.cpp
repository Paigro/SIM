#include "Scene.h"

Scene::Scene()
{
	//sParticles.reserve(100);
}

Scene::~Scene()
{

}

void Scene::update(float t)
{
    // Gestion de las particulas.
    for (auto it = sParticles.begin(); it != sParticles.end(); )
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
}

void Scene::addParticle(Particle* par)
{
	sParticles.emplace_back(par);
}
