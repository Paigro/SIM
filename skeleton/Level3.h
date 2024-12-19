#pragma once

#include "BaseLevelScene.h"


class Level3 : public BaseLevelScene
{
private:

	BlackHole* blackHole = nullptr; // Agujero negro
	SolarWind* solarWind = nullptr; // Viento solar.

public:

	//------Constructoras y destructoras:

	// Constructora del Level3.
	Level3(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj);
	// Destructora del Level3.
	~Level3();


	//------Metodos heredadso:

	// Inicializacion de la escena.
	void initScene() override;
	// Update de Level3.
	void updateScene(float t) override;
};