#pragma once

#include "Scene.h"
#include "RandomGenerator.h"
#include "TornadoForceGenerator.h"

class TornadoScene : public Scene
{
private:

	TornadoForceGenerator* tornadoGen = nullptr; // Generador de tornado.

public:

	//------Constructoras y destructoras:

	// Constructora de TornadoScene.
	TornadoScene();
	// Destructora de TornadoScene.
	~TornadoScene();


	//------Metodos heredados:

	// KeyPressed de TornadoScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	// InitScene de TornadoScene.
	void initScene() override;
};