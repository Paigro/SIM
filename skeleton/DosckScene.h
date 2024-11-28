#pragma once

#include "Scene.h"
#include "SpringForceGenerator.h"
#include "WindForceGenerator.h"	
#include "AnchorForceGenerator.h"
#include "BandForceGenerator.h"


class DosckScene : public Scene
{
private:

	SpringForceGenerator* springForceGen = nullptr;
	WindForceGenerator* windGen = nullptr;

	bool windActive = false;

public:

	//------Constructoras y destructoras:

	// Constructora de DosckScene.
	DosckScene();
	// Destructora de DosckScene.
	~DosckScene();


	//------Metodos heredados:

	//
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	//
	void initScene() override;
};