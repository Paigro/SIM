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
	Particle* parL = new Particle(Vector3(-50, 100, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, Vector4(0, 1, 0, 1), 2);
	parL->setMass(4.0);
	parL->setLifeTime(200);
	// Particula con mas masa.
	Particle* parP = new Particle(Vector3(50, 100, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, Vector4(0, 0, 1, 1), 2);
	parP->setMass(10.0);
	parP->setLifeTime(200);

	// Creamos el anchor del muelle.
	AnchorForceGenerator* anchorFS = new AnchorForceGenerator(Vector3(0, 0, 0), 1, 10, Vector3(0, 0, 0));
	anchorFS->setRadius(400);
	forSys->addForceGenerator(anchorFS);

	// Meter las cosas a la escena.
	addParticle(parL);
	addParticle(parP);*/


	//------Goma de varias particulas:

	// Particulas involucradas.
	Particle* p1 = new Particle(Vector3(50, 0, 50), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, Vector4(1, 1, 1, 1), 2);
	p1->setLifeTime(200);
	p1->setMass(2.0);
	p1->setMovible(false);
	Particle* p2 = new Particle(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, Vector4(1, 1, 0.5, 1), 2);
	p2->setMass(2.0);
	p2->setLifeTime(200);
	Particle* p3 = new Particle(Vector3(0, 0, 50), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, Vector4(1, 0.5, 1, 1), 2);
	p3->setMass(2.0);
	p3->setLifeTime(200);
	Particle* p4 = new Particle(Vector3(0, 50, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, Vector4(0.5, 1, 1, 1), 2);
	p4->setMass(2.0);
	p4->setLifeTime(200);
	Particle* p5 = new Particle(Vector3(50, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.75, Vector4(1, 1, 0, 1), 2);
	p5->setMass(200.0);
	p5->setLifeTime(200);
	//p5->setMovible(false);

	// Gomas involucradas.
	BandForceGenerator* band1FS = new BandForceGenerator(Vector3(50, 0, 50), 500, 5, 1, p1, p2);
	forSys->addForceGenerator(band1FS);
	BandForceGenerator* band2FS = new BandForceGenerator(Vector3(50, 0, 50), 500, 5, 10, p2, p3);
	forSys->addForceGenerator(band2FS);
	BandForceGenerator* band3FS = new BandForceGenerator(Vector3(50, 0, 50), 500, 5, 20, p3, p4);
	forSys->addForceGenerator(band3FS);
	BandForceGenerator* band4FS = new BandForceGenerator(Vector3(50, 0, 50), 500, 5, 5, p4, p5);
	forSys->addForceGenerator(band4FS);

	// Meter las cosas a la escena.
	addParticle(p1);
	addParticle(p2);
	addParticle(p3);
	addParticle(p4);
	addParticle(p5);


	/*//------Flotacion:

	// Particulas involucradas.
	Particle* p6 = new Particle(Vector3(-20, 100, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, Vector4(1, 0.5, 0, 1), 2);
	p6->setMass(10000.0);
	p6->setLifeTime(200);
	Particle* p7 = new Particle(Vector3(20, 100, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, Vector4(1, 0.5, 0, 1), 10);
	p7->setMass(8000000.0);
	p7->setLifeTime(200);
	Particle* p8 = new Particle(Vector3(60, 100, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, Vector4(1, 0.5, 0, 1), 10);
	p8->setMass(10000000.0);
	p8->setLifeTime(200);
	Particle* sea = new Particle(Vector3(0, 40, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 1, Vector4(0, 0, 1, 1), 1);
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
	addParticle(p8);
	addParticle(sea);*/


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