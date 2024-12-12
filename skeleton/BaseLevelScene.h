#pragma once

#include "Scene.h"
#include "Canon.h"


class BaseLevelScene:public Scene
{
private:

	BaseRigidBody* floor = nullptr; // Suelo de la escena.
	DinamicRigidBody* cube = nullptr; // Un cubo.
	DinamicRigidBody* otherCube = nullptr; // Otro cubo.

public:

	//------Constructoras y destructoras:

	// Constructora de BaseLevelScene.
	BaseLevelScene(PxPhysics* physics, PxScene* scene);
	// Destructora de BaseLevelScene.
	~BaseLevelScene();


	//------Metodos heredados:

	// InitScene de BaseLevelScene.
	void initScene() override;
	// KeyPressed de BaseLevelScene.
	void keyPressed(unsigned char key, const physx::PxTransform& camera) override;
};