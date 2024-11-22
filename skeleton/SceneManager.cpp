#include "SceneManager.h"

SceneManager::SceneManager()
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
	if (newSc >= vScenes.size() || vScenes[newSc] == nullptr)
	{
		std::cout << "//------ERROR: No existe la escena: " << newSc << std::endl;

	}
	else
	{
		vScenes[actScene]->deactivateScene();
		actScene = newSc;
		vScenes[actScene]->activateScene();
	}
}

void SceneManager::deleteScene(int delSc)
{

}

void SceneManager::update(float t)
{
	if (vScenes[actScene] != nullptr)
	{
		vScenes[actScene]->updateScene(t);
	}
}