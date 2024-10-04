#include "Projectile.h"

Projectile::Projectile(Vector4 _col, Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam, float _mas, Vector3 _gra)
	: Particle(_col, _pos, _vel, _gra, _dam), mass(_mas), gravity(_gra)
{
	
}

Projectile::~Projectile()
{

}

void Projectile::movement(float t)
{

}
