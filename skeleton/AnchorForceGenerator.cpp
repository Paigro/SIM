#include "AnchorForceGenerator.h"


AnchorForceGenerator::AnchorForceGenerator(Vector3 pos, double _k, double rest, Vector3 anchor_pos)
	: SpringForceGenerator(pos, _k, rest, nullptr)
{
	otherPart = new Particle(anchor_pos, Vector3(0, 0, 0), Vector4(1, 0, 0, 1), 2);
}

AnchorForceGenerator::~AnchorForceGenerator()
{
	delete otherPart;
}