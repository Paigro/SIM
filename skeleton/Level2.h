#pragma once

#include "BaseLevelScene.h"


class Level2 : public BaseLevelScene
{
private:

	SolarWind* solarWind = nullptr; // Viento solar.

public:

	//------Constructoras y destructoras:

	// Constructora del Level2.
	Level2(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj);
	// Destructora del Level2.
	~Level2();


	//------Metodos heredadso:ç
	
	// Inicializacion de la escena.
	void initScene() override;
	// Update de Level2.
	void updateScene(float t) override;


};