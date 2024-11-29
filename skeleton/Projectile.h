#pragma once

#include "Particle.h"


class Projectile : public Particle
{
private:

public:

	//------Constructoras y destructoras:

	// Constructor de Projectile con posicion, velocidad, aceleracion, damping, masa, gravedad que le afecta, color y tamanyo..
	Projectile(Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam, float _mas, Vector4 _col, float _siz);
	// Destructor de Projectile.
	~Projectile();


	//------Metodos heredados:

	// Update de Projectile.
	bool update(float t) override;
};