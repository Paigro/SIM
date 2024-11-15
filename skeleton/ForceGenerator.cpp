#include "ForceGenerator.h"


ForceGenerator::ForceGenerator(Vector3 pos, float rad)
	: position(pos), radius(rad)
{



}

ForceGenerator::~ForceGenerator()
{

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