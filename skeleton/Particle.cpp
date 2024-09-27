#include "Particle.h"

Particle::Particle(Vector3 _pos, Vector3 _vel) : pose(_pos), vel(_vel), acc(0)
{
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(2)), &pose, Vector4{ 1.0, 0.5, 0.0 ,1.0 });
}

Particle::Particle(Vector3 _pos, Vector3 _vel, Vector3 _acc) : pose(_pos), vel(_vel), acc(_acc)
{
	renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(2)), &pose, Vector4{ 1.0, 0.5, 0.0 ,1.0 });
}

Particle::~Particle()
{
	DeregisterRenderItem(renderItem);
}

void Particle::integrate(float t)
{
	if (acc.x != 0 || acc.y != 0 || acc.z != 0)
	{
		pose.p += vel * t;
		vel = vel + (acc * t);
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