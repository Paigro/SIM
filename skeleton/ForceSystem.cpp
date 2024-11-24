#include "ForceSystem.h"


ForceSystem::ForceSystem()
{
	std::cout << "//--MENSAJE: nuevo sitema de fuezas." << std::endl;
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

void ForceSystem::addForceToParticles(std::vector<Projectile*> vPar, float t)
{
	for (auto p : vPar)
	{
		for (auto fg : vFGenerators)
		{
			if (fg->isOnRadius(p->getPos())) // Comprovar que la particula este dentro del radio.
			{
				p->addForce(fg->generateForce(*p)); // Aplicar fuerza.
			}
		}
	}
}