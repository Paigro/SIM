#include "BlackHole.h"

#include "Scene.h"


BlackHole::BlackHole(PxPhysics* gPhysics, PxScene* gScene, Vector3 initPos, float holeSize, Vector3 axis, Scene* mScene)
	: myScene(mScene), size(holeSize)
{
	// He leido que la gravedad de un agujero negro puede ser 3 millones de veces la terrestre, yo voy a poner 40 porque si no es demasiado.
	blackHoleGen = new TornadoForceGenerator(initPos, size, 1.0, axis, 1.0, 40);
	ForceSystem* forSys = new ForceSystem();
	forSys->addForceGenerator(blackHoleGen);
	myScene->addForceSistem(forSys);

	// NOTA: Para la conversion del axis del sistema de fuerzas al sistema de particulas porque van al reves. 
	// El de fuerzas genera la fuerza en el plano perpendicular al eje dado y el de particualas las genera en los ejes dados. Entonces necesito esta conversion.
	if (axis.x == 0) axis.x = 1;
	else axis.x = 0;
	if (axis.y == 0) axis.y = 1;
	else axis.y = 0;
	if (axis.z == 0) axis.z = 1;
	else axis.z = 0;

	ParticleSystem* parSys = new ParticleSystem(new RandomGenerator(initPos, { 0, 0, 0 }, 50, 5, 10, -size / 1.5, size / 1.5, Vector4(0.0, 0.0, 0.0, 1.0), axis, false, 0.5), -1);
	myScene->addParticleSystem(parSys);
}

BlackHole::~BlackHole()
{

}

void BlackHole::setActive(bool act)
{
	//blackHoleBody->setActive(act);
}
