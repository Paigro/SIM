#pragma once

#include "Scene.h"
#include "RandomGenerator.h"
#include "ParticleSystem.h"

class ParSysScene : public Scene
{
private:

	ParticleSystem* fountainParSys = nullptr;
	ParticleSystem* smokeParSys = nullptr;
	ParticleSystem* fireworkParSys = nullptr;
	ParticleSystem* randomParSys = nullptr;

public:

	//------Constructoras y destructoras:

	// Constructora de ParSysScene.
	ParSysScene();
	// Destructora de ParSysScene.
	~ParSysScene();


	//------Metodos heredados:

	//
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
	//
	void initScene() override;
};