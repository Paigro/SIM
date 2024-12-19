#pragma once

#include "ParticleGenerator.h"


class RandomGenerator : public ParticleGenerator
{
private:

	float partSize; // Tamanyo de las particulas generadas.

	float minTimeToLive; // Tiempo minimo que va a vivir cada particula.
	float maxTimeToLive; // Tiempo maximo que va a vivir cada particula.

	float minPos; // Posicion minimo.
	float maxPos; // Posicion maxima.

	Vector4 color; // Color de las particulas que van a salir.

	Vector3 axis; // Eje en el que se crean las particulas.

	bool gravitableParticles; // Si las particulas generadas caen por gravedad o no.

public:

	//------Constructoras y destructoras:

	// Constructora de RandomGenerator.
	RandomGenerator(Vector3 ori, Vector3 vel, int nPar, float minT, float maxT, float minP, float maxP, Vector4 parColor = Vector4{ 1.0, 1.0, 1.0, 1.0 }, Vector3 genAxis = Vector3(1, 1, 1), bool grav = true, float parSize = 1.0);
	// Destructora de RandomGenerator.
	~RandomGenerator();


	//------Metodos heredados:

	// Genera particulas con la diferencia entra las particulas activas y el maximo, las mete a un vector y lo devuelve.
	std::vector<Particle*> CreateParticles(int actP, int maxP) override;
	std::vector<Particle*> CreateParticles() override { return std::vector<Particle*>(); };
};