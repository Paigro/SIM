#include "Scene.h"

//#include "GameManager.h"


#pragma region Constructora y destructora:

Scene::Scene(PxPhysics* physics, PxScene* scene)
	: gPhysics(physics), gScene(scene)
{
	if (physics == nullptr)
	{
		std::cout << "//------ERROR: Fisica es null." << std::endl;
	}
	if (gScene == nullptr)
	{
		std::cout << "//------ERROR: Escena fisica es null." << std::endl;
	}
	initScene();
}

Scene::Scene(PxPhysics* physics, PxScene* scene, GameManager* gm)
	: Scene(physics, scene)
{
	gameMg = gm;
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

	for (auto* fs : vForceSystems)
	{
		delete fs;
	}
	vForceSystems.clear();

	for (auto* rb : vRigidBodies)
	{
		delete rb;
	}
	vRigidBodies.clear();
}

#pragma endregion

#pragma region Update de la escena:

void Scene::updateScene(float t)
{
	// Gestion de las particulas.
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

	// Gestion de los sistemas de particulas.
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
		// Mete fuerza a las particulas sueltas.
		fs->addForceToParticles(vParticles, t);

		// Mete fuerzas a las particulas de los sistemas de particulas.
		for (auto ps : vParticleSystems)
		{
			fs->addForceToParticles(ps->getVParticles(), t);
		}

		fs->addForceToRigidBodies(vRigidBodies, t);
		// Actualiza el sistema de fuerza.
		fs->update(t);
	}

	// Gestion de los solidos rigidos dinamicos.
	for (auto it = vRigidBodies.begin(); it != vRigidBodies.end();)
	{
		BaseRigidBody* rb = *it;
		if (!rb->update(t))
		{
			delete rb;
			it = vRigidBodies.erase(it);
		}
		else
		{
			++it;
		}
	}
}

#pragma endregion

#pragma region Inicializacion, activacion y desactivacion de la escena:

void Scene::initScene()
{

}

void Scene::activateScene()
{
	// Activa las particulas independientes.
	for (auto p : vParticles)
	{
		p->setActive(true);
	}

	// Activa los sistemas de particulas.
	for (auto ps : vParticleSystems)
	{
		ps->setActive(true);
	}

	// Activa los sistemas de fuerzas.
	for (auto fs : vForceSystems)
	{
		fs->setActive(true);
	}

	for (auto drb : vRigidBodies)
	{
		drb->setActive(true);
	}
}

void Scene::deactivateScene()
{
	// Desactiva las particulas independientes.
	for (auto p : vParticles)
	{
		p->setActive(false);
	}

	// Desactiva los sistemas de particulas.
	for (auto ps : vParticleSystems)
	{
		ps->setActive(false);
	}

	// Desactiva los sistemas de fuerzas.
	for (auto fs : vForceSystems)
	{
		fs->setActive(false);
	}

	for (auto drb : vRigidBodies)
	{
		drb->setActive(false);
	}
}

#pragma endregion

#pragma region Meter cosas a la escena:

void Scene::addParticle(Particle* par)
{
	vParticles.emplace_back(par);
}

void Scene::addParticleSystem(ParticleSystem* parSys)
{
	vParticleSystems.emplace_back(parSys);
}

void Scene::addForceSistem(ForceSystem* forSys)
{
	vForceSystems.push_back(forSys);
}

void Scene::addRigidBody(BaseRigidBody* rb)
{
	vRigidBodies.push_back(rb);
}

#pragma endregion