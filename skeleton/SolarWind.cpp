#include "SolarWind.h"

SolarWind::SolarWind(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float radius, float windSpeed, Vector3 windDir, Scene* myScene)
{
	windGen = new WindForceGenerator(initPos, radius, windSpeed, windDir);
	ForceSystem* forSys = new ForceSystem();
	forSys->addForceGenerator(windGen);
	myScene->addForceSistem(forSys);


	ParticleSystem* parSys = new ParticleSystem(new RandomGenerator(initPos, { 0, 0, 0 }, 50, -1, -1, -radius / 1.5, radius / 1.5, Vector4(1.0, 1.0, 0.0, 1.0), Vector3(-1, -1, 0), false, 0.5), -1);
	myScene->addParticleSystem(parSys);
}

SolarWind::~SolarWind()
{

}

void SolarWind::setActive(bool act)
{

}