#include "LevelsScene.h"




LevelsScene::LevelsScene(PxPhysics* physics, PxScene* scene, GameManager* gm)
	: Scene(physics, scene, gm)
{

}

LevelsScene::~LevelsScene()
{

}

void LevelsScene::initScene()
{
	ForceSystem* forSys = new ForceSystem();

	// Particulas involucradas.
	lvl1 = new Particle(Vector3(-170, 40, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, Vector4(0.5, 0.5, 0.5, 1), 10);
	lvl1->setMass(800);
	lvl1->setLifeTime(-1);

	lvl2 = new Particle(Vector3(-110, 40, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, Vector4(0.5, 0.5, 0.5, 1), 10);
	lvl2->setMass(800);
	lvl2->setLifeTime(-1);

	lvl3 = new Particle(Vector3(-50, 40, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 0.5, Vector4(0.5, 0.5, 0.5, 1), 10);
	lvl3->setGravitable(true);
	lvl3->setMass(800);
	lvl3->setLifeTime(-1);

	sea = new Particle(Vector3(-100, -10, 0), Vector3(0, 0, 0), Vector3(0, 0, 0), 1, Vector4(0, 0, 1, 1), 1);
	sea->setMovible(false);
	sea->setLifeTime(-1);
	sea->changeShape(CreateShape(physx::PxBoxGeometry(200, 20, 20)));

	// Flotacion involucrada.
	FlotationForceGenerator* flotationFS = new FlotationForceGenerator(997, 10);
	forSys->addForceGenerator(flotationFS);

	// Metemos las cosas a la escena.
	addParticle(lvl1);
	addParticle(lvl2);
	addParticle(lvl3);
	addParticle(sea);

	addForceSistem(forSys);
}

void LevelsScene::updateScene(float t)
{
	display_text = "Pulsa 1, 2 o 3 para ir al planeta.";
	display_text_position = Vector2(160, 220);
	display_text_color = Vector4(0, 0, 0, 1);

	display_text_2 = " ";
	display_text_position_2 = Vector2(150, 240);
	Scene::updateScene(t);
}

void LevelsScene::activateScene()
{
	levelsResult = gameMg->getLevelResult();
	lvl1->setPos({ -170, 40, 0 });
	lvl2->setPos({ -110, 40, 0 });
	lvl3->setPos({ -50, 40, 0 });

	checkResults();

	Scene::activateScene();
}

void LevelsScene::deactivateScene()
{
	Scene::deactivateScene();
}

void LevelsScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	default:
		break;
	}
}

void LevelsScene::checkResults()
{
	for (auto lvl : levelsResult)
	{
		switch (lvl.first)
		{
		case 3:
			if (lvl.second == true)
			{
				lvl1->setColor(0.0, 1.0, 0.0, 1.0);
			}
			else if (lvl.second == false)
			{
				lvl1->setColor(1.0, 0.0, 0.0, 1.0);
				lvl1->setMss(8000);
			}
			break;
		case 4:
			if (lvl.second == true)
			{
				lvl2->setColor(0.0, 1.0, 0.0, 1.0);
			}
			else if (lvl.second == false)
			{
				lvl2->setColor(1.0, 0.0, 0.0, 1.0);
				lvl2->setMss(8000);
			}
			break;
		case 5:
			if (lvl.second == true)
			{
				lvl3->setColor(0.0, 1.0, 0.0, 1.0);
			}
			else if (lvl.second == false)
			{
				lvl3->setColor(1.0, 0.0, 0.0, 1.0);
				lvl3->setMss(8000);
			}
			break;
		default:
			break;
		}
	}
}