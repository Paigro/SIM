#include "Particle.h"

Particle::Particle(Vector3 _pos, Vector3 _vel)
	: pose(_pos), vel(_vel), acc(0)
{
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(2)), &pose, Vector4{ 1.0, 0.5, 0.0, 1.0 });
	RegisterRenderItem(renderItem);
}

Particle::Particle(Vector3 _pos, Vector3 _vel, Vector3 _acc, float _dam)
	: Particle(_pos, _vel)
{
	acc = _acc;
	damping = _dam;
}

Particle::~Particle()
{
	//DeregisterRenderItem(renderItem); // PAIGRO AQUI: no hace falta hacer un deregister pq delete ya lo hace pero sigue dando error. Ya no da error pero dejo la nota.
}

void Particle::setVel(Vector3 _pos)
{
	pose.p = _pos;
}

void Particle::setPos(Vector3 _vel)
{
	vel = _vel;
}

void Particle::setAcc(Vector3 _acc)
{
	acc = _acc;
}

void Particle::setDamping(float _dam)
{
	damping = _dam;
}

void Particle::setColor(float _r, float _g, float _b, float _a)
{
	renderItem->color.x = _r;
	renderItem->color.y = _g;
	renderItem->color.z = _b;
	renderItem->color.w = _a;
}

bool Particle::update(float t)
{
	if (outOfBounds()) { isAlive = false; }
	if (!isAlive) { return false; } // Comunicarle a la escena que la tiene que eliminar.

	integrate(t); // Movimiento.

	return true;
}

bool Particle::outOfBounds()
{
	// Para eliminar las particulas tras salir de una distancia.
	if (pose.p.x > 100.0 || pose.p.y > 100.0 || pose.p.z > 100.0 ||
		pose.p.x < -100.0 || pose.p.y < -100.0 || pose.p.z < -100.0)
	{
		return true;
	}
	return false;
}

void Particle::integrate(float t)
{
	pose.p += vel * t;

	if (acc.x != 0 || acc.y != 0 || acc.z != 0)
	{
		vel += (acc * t);
		vel *= pow(damping, t);
	}
	else
	{
		pose.p += vel * t;
	}
}

// integrate() con Euler: p += v * t; y v += a * t; cuando anyadamos las leyes de newton.
// Damping para poner un limite a la velocidad. v *= d^t siendo 0 < d < 1 (0.98). Pero probar con varios por probar.
// integrate() con Euler semiimplicito? o Verlet? 
// 
// 
// 
// Euler: x' = f(x, t)  xl+1 = xl + h * f(xi, tl).
// Semi-implicito: priemro calculamos la velocidad y luego la posicon siguiente: v += t * a; p += v * t; v *= d^t.