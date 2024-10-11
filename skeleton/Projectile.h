#pragma once

#include "Particle.h"


class Projectile : public Particle
{
private:

	float mass; // Masa del proyectil.
	Vector3 gravity = { 0.0, -9.8, 0.0 }; // Gravedad que afecta al proyectil.

public:

	//------Constructoras y destructoras:

	// Constructor de Projectile.
	Projectile(Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam, float _mas, Vector3 _gra);
	// Destructor de Projectile.
	~Projectile();


	//------Metodos heredados:

	// Update de Projectile.
	bool update(float t) override;
};



// Daremos velocidad a los proyectiles entre los 5 y 25 m/s para que se puedan apreciar.
// Para ello tendremos que aumentar la masa. Un proyectil de 5 g que sale a 500m/s que le cambiamos la v a 25 m/s tendria una mas de 2 kg.