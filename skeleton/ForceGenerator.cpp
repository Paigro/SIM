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

	if (renderItem != nullptr)
	{
		renderItem = new RenderItem(CreateShape(physx::PxSphereGeometry(radius)), Vector4{ 1.0, 0.5, 0.0, 0.0 });
	}
}

void ForceGenerator::setRadius(float newRad)
{
	radius = newRad;
}

bool ForceGenerator::isOnRadius(Vector3 parPos)
{
	if ((parPos - position).magnitude() <= radius)
	{
		return true;
	}
	return false;
}