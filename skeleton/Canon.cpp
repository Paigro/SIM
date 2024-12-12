#include "Canon.h"

Canon::Canon(int projectiles)
{
	for (int i = 0; i < projectiles; i++)
	{

	}
}

Canon::~Canon()
{
	while (!qRigidBodies.empty())
	{
		delete qRigidBodies.front();
		qRigidBodies.pop();
	}
}

DinamicRigidBody* Canon::shoot()
{
	if (qRigidBodies.empty())
	{
		std::cout << "//--MENSAJE: Al canon no le quedan objetos que lanzar" << std::endl;
		return nullptr;
	}

	DinamicRigidBody* bullet = qRigidBodies.front();
	qRigidBodies.pop();
	return bullet;



}
