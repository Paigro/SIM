#pragma once

#include "BaseLevelScene.h"


class Level2 : public BaseLevelScene
{
private:


public:

	//------Constructoras y destructoras:

	// Constructora del Level2.
	Level2(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj);
	// Destructora del Level2.
	~Level2();


	//------Metodos heredadso:

	// Update de Level2.
	void updateScene(float t) override;


};