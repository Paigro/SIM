#include <ctype.h>

#include <PxPhysicsAPI.h>

#include <vector>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Vector3D.h"
#include "Particle.h"
#include "Projectile.h"
#include "Scene.h"

#include <iostream>

std::string display_text = "This is a test";


using namespace physx;

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

// Particle P1:
Particle* part;
Particle* part2;

// Projectile P1:
Projectile* pro;

// Vector de escenas del juego.
std::vector<Scene*> scenes;

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
	// Particle P1:
	part = new Particle(Vector3{ 0, 0, 0 }, Vector3{ 1, 0, 0 });
	part2 = new Particle(Vector4{ 0.5, 1.0, 0.5, 1.0 }, Vector3{ 0, 0, 0 }, Vector3{ 0, 1, 0 }, Vector3{ 0.0, 2, 0.0 }, 0.98);
	// Projectile P1:
	pro = new Projectile(Vector4{ 0.5, 1.0, 0.5, 1.0 }, Vector3{ 0, 0, 0 }, Vector3{ 0, 25, 25 }, Vector3{ 0.0, 0.0, 2.0 }, 0.98, 2.0, Vector3{ 0.0,-9.8,0.0 });
}


// Function to configure what happens in each step of physics
// interactive: true if the game is rendering, false if it offline
// t: time passed since last call in milliseconds
void stepPhysics(bool interactive, double t)
{
	PX_UNUSED(interactive);

	// Particle P1:
	part->integrate(t);
	part2->integrate(t);

	// Se llama al update de las escenas.
	for (auto s : scenes)
	{
		s->update(t);
	}


	if (pro != nullptr) pro->integrate(t);
	if (pro->getPos().y < 0) delete pro; //Hacerlo dentro de integrate.

	gScene->simulate(t);
	gScene->fetchResults(true);
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
	// Particle P1:
	delete part;
	delete part2;
}

// Function called when a key is pressed
void keyPress(unsigned char key, const PxTransform& camera)
{
	PX_UNUSED(camera);

	switch (toupper(key))
	{
		//case 'B': break;
		//case ' ':	break;
	case ' ':
	{
		break;
	}
	case 'P': // Para disparar un proyectil.

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