#pragma once

#include "Scene.h"
#include "RandomGenerator.h"
#include "ParticleSystem.h"


class ParSysScene : public Scene
{
private:

	ParticleSystem* fountainParSys = nullptr; // Generador de una fuente.
	ParticleSystem* smokeParSys = nullptr; // Generador de humo.
	ParticleSystem* fireworkParSys = nullptr; // generador de un fuego artificial.
	ParticleSystem* randomParSys = nullptr; // Generador de particulas randoms.

public:

	//------Constructoras y destructoras:

	// Constructora de ParSysScene.
	ParSysScene();
	// Destructora de ParSysScene.
	~ParSysScene();


	//------Metodos heredados:

	// InitScene de ParSysScene.
	void initScene() override;
	// KeyPressed de ParSysScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
};