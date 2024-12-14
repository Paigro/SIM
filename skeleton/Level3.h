#pragma once

#include "BaseLevelScene.h"


class Level3 : public BaseLevelScene
{
private:



public:

	//------Constructoras y destructoras:

	// Constructora del Level3.
	Level3(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj);
	// Destructora del Level3.
	~Level3();


	//------Metodos heredadso:

	// Update de Level3.
	void updateScene(float t) override;


};