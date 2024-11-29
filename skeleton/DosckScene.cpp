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
	//------Sistema de fuerzas principal:
	ForceSystem* forSys = new ForceSystem();


	//------Viento:
	windGen = new WindForceGenerator(Vector3{ 0, 0, 0 }, 100, Vector3{ 10, 0, 0 });
	windGen->setActive(false);
	forSys->addForceGenerator(windGen);


	/*//-------Muelle normal:

	// Particula con menos masa.
	Projectile* projL = new Projectile(Vector3(-50, 100, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, 4, Vector4(0, 1, 0, 1), 2);
	projL->setLifeTime(200);
	// Particula con mas masa.
	Projectile* projH = new Projectile(Vector3(50, 100, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, 10, Vector4(0, 0, 1, 1), 2);
	projH->setLifeTime(200);

	// Creamos el anchor del muelle.
	AnchorForceGenerator* anchorFS = new AnchorForceGenerator(Vector3(0, 0, 0), 1, 10, Vector3(0, 0, 0));
	anchorFS->setRadius(400);
	forSys->addForceGenerator(anchorFS);

	// Meter las cosas a la escena.
	addParticle(projL);
	addParticle(projH);*/


	//------Goma de varias particulas:

	/*// Particulas involucradas.
	Projectile* p1 = new Projectile(Vector3(50, 0, 50), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, 2, Vector4(1, 1, 1, 1), 2);
	p1->setLifeTime(200);
	p1->setMovible(false);
	Projectile* p2 = new Projectile(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, 2, Vector4(1, 1, 0.5, 1), 2);
	p2->setLifeTime(200);
	Projectile* p3 = new Projectile(Vector3(0, 0, 50), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, 2, Vector4(1, 0.5, 1, 1), 2);
	p3->setLifeTime(200);
	Projectile* p4 = new Projectile(Vector3(0, 50, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, 2, Vector4(0.5, 1, 1, 1), 2);
	p4->setLifeTime(200);
	Projectile* p5 = new Projectile(Vector3(50, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, 20, Vector4(1, 1, 0, 1), 2);
	p5->setLifeTime(200);
	//p5->setMovible(false);

	// Gomas involucradas.
	BandForceGenerator* band1FS = new BandForceGenerator(Vector3(50, 0, 50), 500, 5, 10, p1, p2);
	forSys->addForceGenerator(band1FS);
	BandForceGenerator* band2FS = new BandForceGenerator(Vector3(50, 0, 50), 500, 5, 10, p2, p3);
	forSys->addForceGenerator(band2FS);
	BandForceGenerator* band3FS = new BandForceGenerator(Vector3(50, 0, 50), 500, 5, 10, p3, p4);
	forSys->addForceGenerator(band3FS);
	BandForceGenerator* band4FS = new BandForceGenerator(Vector3(50, 0, 50), 500, 5, 10, p4, p5);
	forSys->addForceGenerator(band4FS);

	// Meter las cosas a la escena.
	addParticle(p1);
	addParticle(p2);
	addParticle(p3);
	addParticle(p4);
	addParticle(p5);*/


	//------Flotacion:

	// Particulas involucradas.
	Projectile* p6 = new Projectile(Vector3(-20, 100, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, 10000, Vector4(1, 0.5, 0, 1), 2);
	p6->setLifeTime(200);
	Projectile* p7 = new Projectile(Vector3(20, 200, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, 5000000, Vector4(1, 0.5, 0, 1), 10);
	p7->setLifeTime(200);
	Projectile* sea = new Projectile(Vector3(0, 40, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 1, 1, Vector4(0, 0, 1, 1), 1);
	sea->setGravitable(false);
	sea->setMovible(false);
	sea->setLifeTime(-1);
	sea->changeShape(CreateShape(physx::PxBoxGeometry(20, 0.1, 20)));

	// Flotacion involucrada.
	FlotationForceGenerator* flotationFS = new FlotationForceGenerator(997, 40);
	forSys->addForceGenerator(flotationFS);

	// Metemos las cosas a la escena.
	addParticle(p6);
	addParticle(p7);
	addParticle(sea);


	//------Metemos el sistema de fuerzas a la escena:
	addForceSistem(forSys);
}

void DosckScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
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