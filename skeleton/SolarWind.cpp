#include "SolarWind.h"

#include "Scene.h"


SolarWind::SolarWind(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float radius, float windSpeed, Vector3 windDir, Scene* mScene)
	: myScene(mScene)
{
	windGen = new WindForceGenerator(initPos, radius, windSpeed, windDir,0.25);
	ForceSystem* forSys = new ForceSystem();
	forSys->addForceGenerator(windGen);
	myScene->addForceSistem(forSys);

	


	ParticleSystem* parSys = new ParticleSystem(new RandomGenerator(initPos, { 0, 0, 0 }, 50, 2, 6, -radius / 2, radius / 2, Vector4(1.0, 1.0, 0.0, 1.0), Vector3(-1, -1, 0), false, 0.5), -1);
	myScene->addParticleSystem(parSys);
}

SolarWind::~SolarWind()
{

}

void SolarWind::setActive(bool act)
{

}