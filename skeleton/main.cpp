#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include <iostream>

// Clases nuestras;
#include "Vector3D.h"
#include "SceneManager.h"
#include "GameManager.h"
// Escenas:
#include "ExplosionScene.h"
#include "ParSysScene.h"
#include "TornadoScene.h"
#include "WindScene.h"
#include "DosckScene.h"
#include "RigidBodyScene.h"
// Escenas del proyecto final:
#include "InitScene.h"
#include "LevelsScene.h"
#include "TutoScene.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"


using namespace physx;

// esto va en el main.cpp donde esta el display_text
std::string display_text = "This is a test";
physx::PxVec2 display_text_position = Vector2(512 / 2, 512 / 2);
std::string display_text_2 = "This is a test";
physx::PxVec2 display_text_position_2 = Vector2(512 / 2, 512 / 2);
physx::PxVec4 display_text_color = { 1.0f, 0.2f, 0.2f, 1.0f };
int display_text_lineSpacing = 20;

std::string gameManagerText = "This is a test";
physx::PxVec2 gameManagerTextPos = Vector2(512 / 2, 512 / 2);


PxDefaultAllocator		gAllocator;
PxDefaultErrorCallback	gErrorCallback;

PxFoundation* gFoundation = NULL;
PxPhysics* gPhysics = NULL;


PxMaterial* gMaterial = NULL;

PxPvd* gPvd = NULL;

PxDefaultCpuDispatcher* gDispatcher = NULL;
PxScene* gScene = NULL;
ContactReportCallback gContactReportCallback;

// Axis P0:
RenderItem* sSphere = NULL;
RenderItem* xSphere = NULL;
RenderItem* ySphere = NULL;
RenderItem* zSphere = NULL;
PxTransform* sTransform = NULL;
PxTransform* xTransform = NULL;
PxTransform* yTransform = NULL;
PxTransform* zTransform = NULL;
Vector4 sColor(1.0, 1.0, 1.0, 1.0);
Vector4 xColor(1.0, 0.0, 0.0, 1.0);
Vector4 yColor(0.0, 1.0, 0.0, 1.0);
Vector4 zColor(0.0, 0.0, 1.0, 1.0);


// GameManager.
GameManager* gameMg = nullptr;
SceneManager* sceneMg = nullptr;


void initEjes()
{
	sTransform = new PxTransform(Vector3{ 0.0, 0.0, 0.0 });
	xTransform = new PxTransform(Vector3{ 20.0, 0, 0.0 });
	yTransform = new PxTransform(Vector3{ 0.0, 20.0, 0.0 });
	zTransform = new PxTransform(Vector3{ 0.0, 0, 20.0 });
	sSphere = new RenderItem(CreateShape(PxSphereGeometry(1)), sTransform, sColor);
	xSphere = new RenderItem(CreateShape(PxSphereGeometry(1)), xTransform, xColor);
	ySphere = new RenderItem(CreateShape(PxSphereGeometry(1)), yTransform, yColor);
	zSphere = new RenderItem(CreateShape(PxSphereGeometry(1)), zTransform, zColor);

	std::cout << "//--MENSAJE: Ejes creados." << std::endl;
}

void initScenes()
{
	// Escenas del proyecto final:
	sceneMg->addScene(new InitScene(gPhysics, gScene, gameMg));
	sceneMg->addScene(new TutoScene(gPhysics, gScene, gameMg));
	sceneMg->addScene(new LevelsScene(gPhysics, gScene, gameMg));
	sceneMg->addScene(new Level1(gPhysics, gScene, gameMg, 4));
	sceneMg->addScene(new Level2(gPhysics, gScene, gameMg, 2));
	sceneMg->addScene(new Level3(gPhysics, gScene, gameMg, 2));

	std::cout << "//--MENSAJE: Escenas creadas." << std::endl;
}

// Initialize physics engine
void initPhysics(bool interactive)
{
	std::cout << "------------------INIT------------------" << std::endl;
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport, PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(), true, gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	//sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	sceneDesc.gravity = PxVec3(0.0f, 0.0f, 0.0f); // PAIGRO1 AQUI: ADIOS GRAVEDAD JIJIJI.
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);


	//------------Aqui empiezan las practicas:

	// Ejes P0:
	initEjes();

	// Proyecto final:
	sceneMg = new SceneManager(gPhysics, gScene);
	gameMg = new GameManager(gPhysics, gScene, sceneMg);

	// Inicializacion de las escenas.
	initScenes();

	std::cout << "-----------------------------------------" << std::endl << std::endl;
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);


	gameMg->update(t);
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	std::cout << "\n------------------END------------------" << std::endl;
	PX_UNUSED(interactive);

	delete gameMg;

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();

	gFoundation->release();


	// Ejes P0:
	DeregisterRenderItem(sSphere);
	DeregisterRenderItem(xSphere);
	DeregisterRenderItem(ySphere);
	DeregisterRenderItem(zSphere);

	std::cout << "-----------------------------------------" << std::endl;
}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch (toupper(key)) // [!] Poner en mayusculas
	{

	default:
		break;
	}

	if (gameMg != nullptr)
	{
		gameMg->keyPressed(key, camera);
	}

}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
	std::cout << "COLISIOONNNNNNNNNNN entr: " << actor1->getType() << " " << actor2->getType() << std::endl;
	/*if (gameMg != nullptr)
	{
		gameMg->levelHasBeenLost();
	}*/

	PX_UNUSED(actor1);
	PX_UNUSED(actor2);
}


int main(int, const char* const*)
{
#ifndef OFFLINE_EXECUTION
	extern void renderLoop();
	renderLoop();
#else
	static const PxU32 frameCount = 100;
	initPhysics(false);
	for (PxU32 i = 0; i < frameCount; i++)
		stepPhysics(false);
	cleanupPhysics(false);
#endif

	return 0;
}


