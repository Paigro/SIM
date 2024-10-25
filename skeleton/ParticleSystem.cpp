#include "ParticleSystem.h"

#include <iostream>


ParticleSystem::ParticleSystem(Vector3 pos, Vector3 vel, int maxPar, float tim, char typ)
	: initPos(pos), initVel(vel), maxParticles(maxPar), timeToLive(tim), type(typ)
{
	switch (toupper(type))
	{
	case 'F': // Fuente.
		generator = new FountainGenerator(initPos, initVel, maxParticles, 1.0, 5.0);
		break;
	case 'N': // Niebla.

		break;
	case 'C': // Confeti.

		break;
	case 'W': // OPCIONAL: fuego artificial. W de fireWork... :)

		break;
	default:
		break;
	}
	std::cout << "//------NUEVO SISTEMA DE PARTICULAS DE TIPO: " << type << std::endl;
}

ParticleSystem::~ParticleSystem()
{
	for (Projectile* p : vParticles)
	{
		delete p;
	}
	vParticles.clear();
}

bool ParticleSystem::update(float t)
{
	// Actualizacion del tiempo de vida del sistema.
	timeAlive += t;
	if (timeAlive >= timeToLive)
	{
		std::cout << "//------MUERTE SISTEMA DE PARTICULAS DE TIPO: " << type << std::endl;
		return false;
	}

	// Generamos particulas.
	particlesGenerated = generator->CreateParticles(vParticles.size(), maxParticles);

	for (int i = 0; i < particlesGenerated.size(); i++)
	{
		vParticles.push_back(particlesGenerated[i]);
	}

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
	return true;
}