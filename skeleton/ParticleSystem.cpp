#include "ParticleSystem.h"

#include <iostream>


ParticleSystem::ParticleSystem(Vector3 pos, Vector3 vel, int maxPar, float tim, char typ, Vector4 parColor)
	: initPos(pos), initVel(vel), maxParticles(maxPar), timeToLive(tim), type(typ), timeAlive(0)
{
	switch (toupper(type))
	{
	case 'F': // Fuente.
		generator = new FountainGenerator(initPos, initVel, maxParticles, 2.0, 6.0);
		break;
	case 'S': // Humo.
		generator = new SmokeGenerator(initPos, initVel, maxParticles, 4.0, 8.0);
		break;
	case 'R': // LLuvia.
		// PAIGRO2 AQUI: TODO
	case 'N': // Niebla.
		// PAIGRO2 AQUI: TODO
		break;
	case 'W': // OPCIONAL: fuego artificial. W de fireWork... :)
		generator = new FireworkGenerator(initPos, initVel, maxParticles, 4.0, 4.0, 50);
		break;
	case 'G': // Generador aleatorio.
		generator = new RandomGenerator(initPos, initVel, maxPar, 4.0, 10.0, 0.0, 50.0, parColor);
		break;
	default:
		break;
	}

	std::cout << "//--MENSAJE: Nuevo SISTEMA DE PARTICULAS de tipo: " << type << std::endl;

	if (timeToLive < 0.0)
	{
		dieByTime = false;
		std::cout << "//----AVISO: ParticleSystem " << type << " tiene tiempo infinito." << std::endl;
	}
	else
	{
		dieByTime = true;
		std::cout << "//----AVISO: ParticleSystem " << type << " muere en t: " << timeToLive << std::endl;
	}
}

ParticleSystem::~ParticleSystem()
{
	for (Particle* p : vParticles)
	{
		delete p;
	}
	vParticles.clear();
}

bool ParticleSystem::update(float t)
{
	// Por si acaso.
	if (generator == nullptr)
	{
		std::cout << "//------ERROR: Sistema de particulas de tipo " << type << " no tiene generador." << std::endl;
		return false;
	}

	if (!isActive) { return true; }

	// Actualizacion del tiempo de vida del sistema.
	if (dieByTime)
	{
		timeAlive += t;
		if (timeAlive >= timeToLive)
		{
			std::cout << "//--MENSAJE: Muerte de sistema de particulas de tipo: " << type << std::endl;
			return false;
		}
	}

	// Generamos particulas.
	particlesGenerated = generator->CreateParticles(vParticles.size(), maxParticles);

	// Las guardamos en el sistema.
	for (int i = 0; i < particlesGenerated.size(); i++)
	{
		vParticles.push_back(particlesGenerated[i]);
	}

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
	return true;
}

void ParticleSystem::setActive(bool act)
{
	isActive = act;

	for (auto p : vParticles)
	{
		p->setActive(act);
	}

	generator->setActive(act);
}