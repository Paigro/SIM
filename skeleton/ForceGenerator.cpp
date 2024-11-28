#include "ForceGenerator.h"


ForceGenerator::ForceGenerator(Vector3 pos, float rad)
	: position(pos), radius(rad)
{
	generateSphere();
}

ForceGenerator::~ForceGenerator()
{

}

void ForceGenerator::generateSphere()
{
	if (radius <= 0)
	{
		return;
	}

	if (!renderItem) {
		renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(radius)), Vector4{ 1.0, 0.5, 0.0, 0.0 });
	}
	else
	{
		DeregisterRenderItem(renderItem);
		renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(radius)), Vector4{ 1.0, 0.5, 0.0, 0.0 });
	}
}

void ForceGenerator::setRadius(float newRad)
{
	radius = newRad;
	generateSphere();
}

bool ForceGenerator::isOnRadius(Particle* part)
{
	Vector3 partPos = part->getPos();
	if ((partPos - position).magnitude() <= radius)
	{
		return true;
	}
	return false;
}

void ForceGenerator::isActive(bool act)
{
	if (!act)
	{
		DeregisterRenderItem(renderItem);
	}
}