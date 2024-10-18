#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include <iostream>

// Clases nuestras;
#include "Vector3D.h"
#include "Particle.h"
#include "Projectile.h"
#include "Scene.h"
#include "ParticleSystem.h"


using namespace physx;


std::string display_text = "This is a test";


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
RenderItem* sphere = NULL;
RenderItem* xSphere = NULL;
RenderItem* ySphere = NULL;
RenderItem* zSphere = NULL;
PxTransform* sphereTransform = NULL;
PxTransform* xTransform = NULL;
PxTransform* yTransform = NULL;
PxTransform* zTransform = NULL;
Vector4 sphereColor(1.0, 1.0, 1.0, 1.0);
Vector4 sphereXColor(1.0, 0.0, 0.0, 1.0);
Vector4 sphereYColor(0.0, 1.0, 0.0, 1.0);
Vector4 sphereZColor(0.0, 0.0, 1.0, 1.0);

//------P1:

Particle* part = nullptr;
Particle* part2 = nullptr;
Projectile* pro = nullptr;


//------Scenes:

std::vector<Scene*> scenes; // Vector de escenas del juego.
Scene* scene = nullptr; // Primera escena de prueba.

// Particle System P2:
ParticleSystem* parSys = nullptr;

// Initialize physics engine
void initPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	gFoundation = PxCreateFoundation(PX_FOUNDATION_VERSION, gAllocator, gErrorCallback);

	gPvd = PxCreatePvd(*gFoundation);
	PxPvdTransport* transport = PxDefaultPvdSocketTransportCreate(PVD_HOST, 5425, 10);
	gPvd->connect(*transport, PxPvdInstrumentationFlag::eALL);

	gPhysics = PxCreatePhysics(PX_PHYSICS_VERSION, *gFoundation, PxTolerancesScale(), true, gPvd);

	gMaterial = gPhysics->createMaterial(0.5f, 0.5f, 0.6f);

	// For Solid Rigids +++++++++++++++++++++++++++++++++++++
	PxSceneDesc sceneDesc(gPhysics->getTolerancesScale());
	sceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
	gDispatcher = PxDefaultCpuDispatcherCreate(2);
	sceneDesc.cpuDispatcher = gDispatcher;
	sceneDesc.filterShader = contactReportFilterShader;
	sceneDesc.simulationEventCallback = &gContactReportCallback;
	gScene = gPhysics->createScene(sceneDesc);

	// Axis P0:
	sphereTransform = new PxTransform(Vector3{ 0.0, 0.0, 0.0 });
	xTransform = new PxTransform(Vector3{ 20.0, 0, 0.0 });
	yTransform = new PxTransform(Vector3{ 0.0, 20.0, 0.0 });
	zTransform = new PxTransform(Vector3{ 0.0, 0, 20.0 });
	sphere = new RenderItem(CreateShape(PxSphereGeometry(2)), sphereTransform, sphereColor);
	xSphere = new RenderItem(CreateShape(PxSphereGeometry(2)), xTransform, sphereXColor);
	ySphere = new RenderItem(CreateShape(PxSphereGeometry(2)), yTransform, sphereYColor);
	zSphere = new RenderItem(CreateShape(PxSphereGeometry(2)), zTransform, sphereZColor);

	scene = new Scene();
	scenes.push_back(scene);

	scene->addParticle(new Particle(Vector3{ 0, 0, 0 }, Vector3{ 1, 0, 0 }));
	scene->addParticle(new Particle(Vector3{ 0, 0, 0 }, Vector3{ 0, 1, 0 }, Vector3{ 0.0, 4.0, 0.0 }, 0.98));
	scene->addParticle(new Projectile(Vector3{ 0, 0, 0 }, Vector3{ 0, 25, 25 }, Vector3{ 0.0, 0.0, 4.0 }, 0.98, 2.0, Vector3{ 0.0,-9.8,0.0 }));

	// Particle System P2:
	parSys = new ParticleSystem(new Particle(Vector3(0, 0, 0), Vector3(0, 0, 0), Vector3(0, 0, 4), 0.98), Vector3(0, 1, 0.5), Vector3(), 200);
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	gScene->simulate(t);
	gScene->fetchResults(true);

	// Se llama al update de las escenas.
	for (auto s : scenes)
	{
		s->update(t);
	}
	// Particle System P2:
	parSys->update(t);
}

// Function to clean data
// Add custom code to the begining of the function
void cleanupPhysics(bool interactive)
{
	PX_UNUSED(interactive);

	// Rigid Body ++++++++++++++++++++++++++++++++++++++++++
	gScene->release();
	gDispatcher->release();
	// -----------------------------------------------------
	gPhysics->release();
	PxPvdTransport* transport = gPvd->getTransport();
	gPvd->release();
	transport->release();

	gFoundation->release();

	// Axis P0:
	DeregisterRenderItem(sphere);
	DeregisterRenderItem(xSphere);
	DeregisterRenderItem(ySphere);
	DeregisterRenderItem(zSphere);

	// Particle System P2:

}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch (toupper(key)) // [!] Poner en mayusculas 
	{
		//case 'B': break;
		//case ' ':	break;
	case ' ':
	{
		break;
	}
	case 'P': // Para disparar un proyectil.
		std::cout << "Disparo" << std::endl;
		scene->addParticle(new Projectile(GetCamera()->getTransform().p, GetCamera()->getTransform().q.getBasisVector2() * -20, Vector3{ 0.0, 0.0, 4.0 }, 0.98, 2.0, Vector3{ 0.0,-9.8,0.0 }));
		break;
	default:
		break;
	}
}

void onCollision(physx::PxActor* actor1, physx::PxActor* actor2)
{
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