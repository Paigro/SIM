#include "SceneManager.h"

SceneManager::SceneManager(PxPhysics* physics, PxScene* scene)
{

}

SceneManager::~SceneManager()
{
	for (auto* s : vScenes)
	{
		delete s;
	}
	vScenes.clear();
	std::cout << "//--MENSAJE: SceneManager eliminado." << std::endl;
}

void SceneManager::addScene(Scene* sc)
{
	if (sc != nullptr)
	{
		vScenes.push_back(sc);
		std::cout << "\n//--MENSAJE: NUEVA ESCENA: " << vScenes.size() - 1 << std::endl;
		sc->initScene();
		if (vScenes.size() - 1 != actScene)
		{
			sc->deactivateScene();
		}
	}
	else
	{
		std::cout << "\n//------ERROR: No se ha podido meter escena." << std::endl;
	}
}

void SceneManager::changeScene(int newSc)
{
	if (actScene == newSc) 
	{ 
		std::cout << "//----AVISO: Ya estas en la escena: " << newSc << std::endl;
		return; 
	}

	if (newSc >= vScenes.size() || vScenes[newSc] == nullptr)
	{
		std::cout << "//------ERROR: No existe la escena: " << newSc << std::endl;
	}
	else
	{
		vScenes[actScene]->deactivateScene();
		std::cout << "//--MENSAJE: Escena " << actScene << " desactivada." << std::endl;
		actScene = newSc;
		vScenes[actScene]->activateScene();
		std::cout << "//--MENSAJE: Escena " << actScene << " activada." << std::endl;
	}
}

void SceneManager::nextScene()
{
	if (actScene == vScenes.size() - 1)
	{
		changeScene(0);
	}
	else
	{
		changeScene(actScene + 1);
	}
}

void SceneManager::prevScene()
{
	if (actScene == 0)
	{
		changeScene(vScenes.size() - 1);
	}
	else
	{
		changeScene(actScene - 1);
	}
}

void SceneManager::deleteScene(int delSc)
{

}

void SceneManager::update(float t)
{
	if (!vScenes.empty())
	{
		if (vScenes[actScene] != nullptr)
		{
			vScenes[actScene]->updateScene(t);
		}
	}
}

void SceneManager::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	/*switch (toupper(key))
	{
	case '0': // Escena con los sistemas de particulas.
		changeScene(0);
		break;
	case '1': // Escena con el viento.
		changeScene(1);
		break;
	case '2': // EScena con el torbellino.
		changeScene(2);
		break;
	case '3': // Escena con la explosion.
		changeScene(3);
		break;
	case '4': // Escena con todos los muelles.
		changeScene(4);
		break;
	case '5': // Escena con los solidos rigidos.
		changeScene(5);
		break;
	case '6':
		changeScene(6);
		break;
	case '7':
		//changeScene(7);
		//break;
	case '8':
		//changeScene(8);
		//break;
	case '9':
		//changeScene(9);
		//break;
		std::cout << "//----AVISO: no existe la escena: " << key << std::endl;
		break;
	}*/

	// Llamar al keyPressed de la escena activa.
	vScenes[actScene]->keyPressed(key, camera);
}