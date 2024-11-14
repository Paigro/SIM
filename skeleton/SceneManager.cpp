#include "SceneManager.h"

SceneManager::SceneManager(Vector3 ori, Vector3 vel, int nPar, float minT, float maxT)
{



}

SceneManager::~SceneManager()
{
	for (auto* s : vScenes)
	{
		delete s;
	}
	vScenes.clear();
}

void SceneManager::addScene(Scene* sc)
{
	if (sc != nullptr) 
	{
		vScenes.push_back(sc);
		sc->initScene();
	}
}

void SceneManager::changeScene(int newSc)
{



}

void SceneManager::deleteScene(int delSc)
{



}

void SceneManager::update(float t)
{



}