#pragma once

#include "Scene.h"
#include "Canon.h"
#include "Planet.h"
#include "BlackHole.h"
#include "SolarWind.h"

const float SHOOT_FORCE = 800;

const Vector3 PLANET_POS = Vector3(-150, 0, 0);

class BaseLevelScene : public Scene
{
protected:

	//------Obejtos de la escena.

	Canon* canon = nullptr; // Referencia al canon.
	Planet* planet = nullptr; // Referencia al planet.
	BlackHole* blackHole = nullptr; // Agujero negro
	SolarWind* solarWind = nullptr; // Viento solar.

	int angle; // Angulo que tiene el canon.
	Vector3 direction; // Direccion para el lanzamiento del canon dependiendo del angulo.
	float baseForce; // Fuerza que se le aplica al disparo.
	int forceMultiplier; // Multiplicador de fuerza que se le aplica al disparo.

	int objetive; // Numero de satelites que hay que poner en orbita.

	bool canShoot = true; // Controlador del disparo.
	float shootRecharge = 0; // Cooldown del disparo.

public:

	//------Constructoras y destructoras:

	// Constructora de BaseLevelScene.
	BaseLevelScene(PxPhysics* physics, PxScene* scene, GameManager* gm, int obj);
	// Destructora de BaseLevelScene.
	~BaseLevelScene();


	//------Metodos heredados:

	// Inicializacion de la escena.
	virtual void initScene() override;
	// Update de BaseLevelScene.
	virtual void updateScene(float t) override;
	// Activa la escena de BaseLevelScene.
	virtual void activateScene() override;
	// Desactiva la escena de BaseLevelScene.
	virtual void deactivateScene() override;
	// KeyPressed virtual de BaseLevelScene.
	virtual void keyPressed(unsigned char key, const physx::PxTransform& camera) override;


	//------Metodos de la escena:

	// Calcular la fuerza de disparo de la bala.
	Vector3 calculateForce();
	//
	bool outOfLevel(Vector3 objPos);
};