#include "ForceSystem.h"


ForceSystem::ForceSystem()
{
	std::cout << "//--MENSAJE: Nuevo SISTEMA DE FUERZAS." << std::endl;
}

ForceSystem::~ForceSystem()
{
	for (auto fg : vFGenerators)
	{
		delete fg;
	}
	vFGenerators.clear();
}

void ForceSystem::addForceGenerator(ForceGenerator* fGen)
{
	vFGenerators.push_back(fGen);
}

void ForceSystem::update(float t)
{
	if (!isActive) { return; }

	for (auto fg : vFGenerators)
	{
		fg->updateFGen(t);
	}
}

void ForceSystem::setActive(bool act)
{
	isActive = act;

	for (auto fs : vFGenerators)
	{
		fs->isActive(act);
	}
}

void ForceSystem::addForceToParticles(std::vector<Particle*> vPar, float t)
{
	for (auto p : vPar)
	{
		for (auto fg : vFGenerators)
		{
			if (fg->isOnRadius(p->getPos())) // Comprobar que la particula este dentro del radio.
			{
				p->addForce(fg->generateForce(*p)); // Aplicar fuerza.
			}
		}
	}
}

void ForceSystem::addForceToRigidBodies(std::vector<BaseRigidBody*> vRB, float t)
{
	/*for (auto rb : vRB)
	{
		for (auto fg : vFGenerators)
		{
			if (fg->isOnRadius(rb->getPose().p)) // Comprobar que la particula este dentro del radio.
			{
				rb->addForce(fg->generateForce(*p)); // Aplicar fuerza.
			}
		}
	}*/
	std::cout << "//----------NO ESTA TODAVIA PAIGRO NO FUNCIONAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA" << std::endl;
}