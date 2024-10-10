#pragma once

#include <vector>

#include "Particle.h"

class Scene
{
private:

	std::vector<Particle*> sParticles; // Vector de particulas de la escena.

public:

	//------Constructoras y destructoras:

	// Constructora de Scene.
	Scene();
	// Destructora de scene.
	~Scene();


	//------Metodos de la escena.

	// Update de Scene.
	void update(float t);


	//------Metodos para meter cosas a la escena:

	// Mete una particula.
	void addParticle(Particle* par);
};