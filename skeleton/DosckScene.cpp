#include "DosckScene.h"


DosckScene::DosckScene()
	: Scene()
{

}

DosckScene::~DosckScene()
{

}

void DosckScene::initScene()
{
	// Viento
	ForceSystem* forSys = new ForceSystem();
	windGen = new WindForceGenerator(Vector3{ 0, 0, 0 }, 100, Vector3{ 10, 0, 0 });
	forSys->addForceGenerator(windGen);


	Projectile* proj = new Projectile(Vector3(-50, 60, 50), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, 4, Vector4(1, 0.5, 0, 1), 2);
	proj->setLifeTime(200);

	AnchorForceGenerator* anchor = new AnchorForceGenerator(Vector3(50, 50, 50), 5, 40, Vector3(50, 50, 50));
	anchor->setRadius(200);

	forSys->addForceGenerator(anchor);


	addParticle(proj);
	addForceSistem(forSys);
}

void DosckScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	case 'V':
		windActive = !windActive;
		windGen->setActive(windActive);
	default:
		break;
	}
}