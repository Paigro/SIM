#pragma once

#include <PxPhysicsAPI.h>

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Scene.h"

class SceneManager
{
private:

	std::vector<Scene*> vScenes; // Vector de escenas.

	int actScene = 0;

public:

	//------Constructoras y destructoras:

	// Constructora de SceneManager.
	SceneManager(Vector3 ori, Vector3 vel, int nPar, float minT, float maxT);
	// Destructora de SceneManager.
	~SceneManager();


	//------Gestion de escenas:
	
	// Meter una escena nueva.
	void addScene(Scene* sc);
	// Cambiar a otra escena.
	void changeScene(int newSc);
	// Eliminar escena.
	void deleteScene(int delSc);


	//------Update de las escenas:
	void update(float t);
};