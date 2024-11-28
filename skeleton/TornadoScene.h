#pragma once

#include "Scene.h"
#include "RandomGenerator.h"
#include "TornadoForceGenerator.h"

class TornadoScene : public Scene
{
private:

	TornadoForceGenerator* tornadoGen = nullptr;

public:

	//------Constructoras y destructoras:

	// Constructora de TornadoScene.
	TornadoScene();
	// Destructora de TornadoScene.
	~TornadoScene();


	//------Metodos heredados:

	//
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	//
	void initScene() override;
};