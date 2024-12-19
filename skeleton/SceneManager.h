#pragma once

#include "core.hpp"
#include "RenderUtils.hpp"
#include "callbacks.hpp"

#include "InitScene.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"


class SceneManager
{
private:

	std::vector<Scene*> vScenes; // Vector de escenas.

	int actScene = 0; // Indice de la escena actual.

public:

	//------Constructoras y destructoras:

	// Constructora de SceneManager.
	SceneManager(PxPhysics* physics, PxScene* scene);
	// Destructora de SceneManager.
	~SceneManager();


	//------Gestion de escenas:

	// Mete una escena nueva.
	void addScene(Scene* sc);
	// Cambia a otra escena.
	void changeScene(int newSc);
	// Progresa a la siguiente escena.
	void nextScene();
	// Retrocede a la anterior escena.
	void prevScene();
	// Eliminar escena.
	void deleteScene(int delSc);


	//------Metodos de SceneManager:

	// Update de las escenas.
	void update(float t);
	// KeyPressed del SceneManager.
	void keyPressed(unsigned char key, const physx::PxTransform& camera);


	//------Getters y stetters:

	// Devuelve el vector de escenas.
	const std::vector<Scene*> getVScenes() { return vScenes; }
	// Devuelve el nivel actual.
	const int getActLevel() { return actScene; }
};