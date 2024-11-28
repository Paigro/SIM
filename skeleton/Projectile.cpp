#include "Projectile.h"


Projectile::Projectile(Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam, float _mas, Vector4 _col, float _siz)
	: Particle(_pos, _vel, _acc, _dam, _col, _siz, _mas), mass(_mas)
{

}

Projectile::~Projectile()
{

}

bool Projectile::update(float t)
{
	return Particle::update(t);
}