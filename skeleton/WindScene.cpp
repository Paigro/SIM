#include "WindScene.h"


WindScene::WindScene(PxPhysics* physics, PxScene* scene)
	: Scene(physics, scene)
{

}

WindScene::~WindScene()
{

}

void WindScene::initScene()
{
	// Sistema de particulas aleatorias.
	addParticleSystem(new ParticleSystem(Vector3{ 0, 0, 0 }, Vector3{ 0, 0, 0 }, 200, -1, 'G'));

	// Sistema de fuerzas.
	ForceSystem* forSys = new ForceSystem();

	// Viento.
	windGen = new WindForceGenerator(Vector3{ 0, 0, 0 }, 100, Vector3{ 10, 0, 0 });

	// Se la metemos al sistema.
	forSys->addForceGenerator(windGen);

	// Se lo metemos a la escena.
	addForceSistem(forSys);
}

void WindScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case 'V':
		windActive = !windActive;
		if (windGen != nullptr) { windGen->setActive(windActive); }
		else { std::cout << "//------ERROR: viento no existe." << std::endl; }
	default:
		break;
	}
}