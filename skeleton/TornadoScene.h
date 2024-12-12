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
	TornadoScene(PxPhysics* physics, PxScene* scene);
	// Destructora de TornadoScene.
	~TornadoScene();


	//------Metodos heredados:

	// InitScene de TornadoScene.
	void initScene() override;
	// KeyPressed de TornadoScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
};