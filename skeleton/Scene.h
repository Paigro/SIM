#pragma once

#include <vector>

#include "Particle.h"
#include "Projectile.h"

class Scene
{
private:

	std::vector<Particle*> particles; // Vector de particulas de la escena.

public:

	//------Constructoras y destructoras:

	// Constructora de Scene.
	Scene();
	// Destructora de scene.
	~Scene();


	//------

	// Update de Scene.
	void update(float t);

};

