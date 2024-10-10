#include "Projectile.h"

Projectile::Projectile(Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam, float _mas, Vector3 _gra)
	: Particle(_pos, _vel, _gra, _dam), mass(_mas), gravity(_gra)
{

}

Projectile::~Projectile()
{

}

bool Projectile::update(float t)
{
	return Particle::update(t);
}