#pragma once

#include "Scene.h"

#include "WindForceGenerator.h"	

#include "SpringForceGenerator.h"
#include "AnchorForceGenerator.h"
#include "BandForceGenerator.h"
#include "FlotationForceGenerator.h"


class DosckScene : public Scene
{
private:

	WindForceGenerator* windGen = nullptr; // Generador de viento.
	SpringForceGenerator* springForceGen = nullptr; // Generador de fuerzas muelle.

	bool windActive = false; // Para controlar el viento.

public:

	//------Constructoras y destructoras:

	// Constructora de DosckScene.
	DosckScene();
	// Destructora de DosckScene.
	~DosckScene();


	//------Metodos heredados:

	// InitScene de DosckScene.
	void initScene() override;
	// KeyPressed de DosckScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
};