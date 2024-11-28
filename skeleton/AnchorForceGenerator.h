#pragma once

#include "SpringForceGenerator.h"


class AnchorForceGenerator : public SpringForceGenerator
{
private:

public:

	//------Constructoras y destructoras:

	// Constructora AnchorForceGenerator.
	AnchorForceGenerator(Vector3 pos, double _k, double rest, Vector3 anchor_pos);
	// Destructora de AnchorForceGenerator.
	~AnchorForceGenerator();


	//------Metodos de AnchorForceGenerator:

	//
};