#pragma once

#include "BaseLevelScene.h"


class Level4 : public BaseLevelScene
{
private:



public:

	//------Constructoras y destructoras:

	// Constructora del Level4.
	Level4(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj);
	// Destructora del Level4.
	~Level4();


	//------Metodos heredadso:

	// Update de Level4.
	void updateScene(float t) override;


};