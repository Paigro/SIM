#include "Canon.h"


Canon::Canon(PxPhysics* physics, PxScene* scene, Vector3 initPos, int projectiles)
	: gPhysics(physics), gScene(scene), position(initPos)
{
	bulletPosition = position - Vector3(4, 0, 0);

	canonBody = new Particle(initPos, Vector3(0, 0, 0), Vector4(0, 0, 0, 1));
	canonBody->setGravitable(false);
	canonBody->setMovible(false);
	canonBody->changeShape(CreateShape(physx::PxBoxGeometry(Vector3(4, 2, 2))));


	for (int i = 0; i < projectiles; i++)
	{
		DinamicRigidBody* bullet = new DinamicRigidBody(gPhysics, gScene, PxTransform(initPos), CreateShape(physx::PxSphereGeometry(2.0)), Vector4(0.5, 0.5, 0.5, 1.0), Vector3(2, 2, 2));
		bullet->setActive(false);
		bullet->setLifeTime(-1);
		qRigidBodies.push(bullet);
	}

	// Preparamos el primer disparo.
	if (qRigidBodies.size() >= 1)
	{
		prepareSoot();
	}

	std::cout << "//--MENSAJE: Canon creado con " << qRigidBodies.size() << " disparos" << std::endl;
}

Canon::~Canon()
{
	delete canonBody; // Elimina la particula que hace de cuerpo.

	while (!qRigidBodies.empty()) // Vacia la cola.
	{
		delete qRigidBodies.front();
		qRigidBodies.pop();
	}
}

void Canon::setActive(bool act)
{
	canonBody->setActive(act); // Activa/desactiva el cuerpo del canon.

	if (!qRigidBodies.empty())
	{
		qRigidBodies.front()->setActive(act); // Solo activa/desactiva la primera de la cola, el resto estan desactivados siempre.
	}
}

DinamicRigidBody* Canon::shoot()
{
	if (qRigidBodies.empty())
	{
		std::cout << "//--MENSAJE: Al canon no le quedan objetos que lanzar." << std::endl;
		return nullptr;
	}

	DinamicRigidBody* bullet = qRigidBodies.front(); // Hay que gurdarla para no perderla con el pop.
	qRigidBodies.pop();

	std::cout << "//--MENSAJE: PIIIUUUMMM" << std::endl;
	return bullet; // Ahora que la gestione la escena. jeje
}

void Canon::prepareSoot()
{
	if (!qRigidBodies.empty())
	{
		DinamicRigidBody* nextBullet = qRigidBodies.front();
		if (nextBullet->getIsActive())
		{
			return;
		}
		nextBullet->setActive(true);
		nextBullet->setPose(PxTransform(bulletPosition));
	}
}

void Canon::addShoots(int addedShoots)
{
	for (int i = 0; i < addedShoots; i++)
	{
		DinamicRigidBody* bullet = new DinamicRigidBody(gPhysics, gScene, PxTransform(position), CreateShape(physx::PxSphereGeometry(2.0)), Vector4(0.5, 0.5, 0.5, 1.0), Vector3(2, 2, 2));
		bullet->setActive(false);
		bullet->setLifeTime(-1);
		qRigidBodies.push(bullet);
	}
	prepareSoot();
	std::cout << "//--MENSAJE: Canon tiene " << addedShoots << " shoots mas." << std::endl;
}