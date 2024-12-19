#pragma once

#include "BaseLevelScene.h"


class Level1 : public BaseLevelScene
{
private:

public:

	//------Constructoras y destructoras:

	// Constructora del Level1.
	Level1(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj);
	// Destructora del Level1.
	~Level1();


	//------Metodos heredadso:

	// Inicializacion de la escena.
	void initScene() override;
	// Update de Level1.
	void updateScene(float t) override;


};