#include "RigidBodyScene.h"

RigidBodyScene::RigidBodyScene(PxPhysics* physics, PxScene* scene)
	: Scene(physics, scene)
{

}

RigidBodyScene::~RigidBodyScene()
{
	delete floor;
	delete cube;
	delete otherCube;
}

void RigidBodyScene::initScene()
{
	PxTransform floorPose(Vector3(0, 0, 0));
	floor = new StaticRigidBody(gPhysics, gScene, floorPose, CreateShape(physx::PxBoxGeometry(Vector3(100, 1, 100))), Vector4(0.5, 0.5, 0.5, 1.0), Vector3(100, 1, 100));
	floor->setLifeTime(-1);

	PxTransform cubePose(Vector3(50, 100, 0));
	cube = new DinamicRigidBody(gPhysics, gScene, cubePose, CreateShape(physx::PxBoxGeometry(Vector3(4, 4, 4))), Vector4(0.76, 0.34, 0.20, 1.0), Vector3(4, 4, 4), 1);

	PxTransform otherCubePose(Vector3(-50, 100, 0));
	otherCube = new DinamicRigidBody(gPhysics, gScene, otherCubePose, CreateShape(physx::PxBoxGeometry(Vector3(4, 4, 4))), Vector4(0, 0.26, 0.41, 1.0), Vector3(4, 4, 4), 20);

	addRigidBody(floor);
	addRigidBody(cube);
	addRigidBody(otherCube);
}

void RigidBodyScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	default:
		break;
	}
}