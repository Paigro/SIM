#pragma once

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "Scene.h"


class SceneManager
{
private:

	std::vector<Scene*> vScenes; // Vector de escenas.

	int actScene = 0; // Indice de la escena actual.

public:

	//------Constructoras y destructoras:

	// Constructora de SceneManager.
	SceneManager();
	// Destructora de SceneManager.
	~SceneManager();


	//------Gestion de escenas:
	
	// Mete una escena nueva.
	void addScene(Scene* sc);
	// Cambia a otra escena.
	void changeScene(int newSc);
	// Eliminar escena.
	void deleteScene(int delSc);


	//------Metodos de SceneManager:

	// Update de las escenas.
	void update(float t);
	// KeyPressed del SceneManager.
	void keyPressed(unsigned char key, const physx::PxTransform& camera);
};