#include "EndScene.h"

EndScene::EndScene(PxPhysics* physics, PxScene* scene, GameManager* gm)
	: Scene(physics, scene, gm)
{

}

EndScene::~EndScene()
{

}

void EndScene::initScene()
{
	Particle* button1 = new Particle(Vector3(-115.0, -30.0f, 0.0), Vector3(0, 0, 0), Vector4(1, 1, 1, 1));
	button1->changeShape(CreateShape(PxCapsuleGeometry(20, 10)));
	button1->setLifeTime(-1);
	button1->setGravitable(false);
	button1->setMovible(false);

	addParticle(button1);

	ParticleSystem* smoke1 = new ParticleSystem(new SmokeGenerator(Vector3(-200, 130, 0), { 0, 0, 0 }, 50, 10.0, 15.0, Vector4(1.0, 1.0, 1.0, 0.5)), -1);
	ParticleSystem* smoke2 = new ParticleSystem(new SmokeGenerator(Vector3(-40, 130, 0), { 0, 0, 0 }, 50, 10.0, 15.0, Vector4(1.0, 1.0, 1.0, 0.5)), -1);

	addParticleSystem(smoke1);
	addParticleSystem(smoke2);
}

void EndScene::updateScene(float t)
{
	display_text = "Has completado " + std::to_string(levelsWon) + "/" + std::to_string(totalLevels);
	display_text_position = Vector2(200, 315);
	display_text_color = Vector4(0, 0, 0, 1);

	display_text_2 = "SALIR (exit)";
	display_text_position_2 = Vector2(210, 180);

	Scene::updateScene(t);
}

void EndScene::activateScene()
{
	std::pair<int, int> results = gameMg->getWonsAndTotal();
	levelsWon = results.first;
	totalLevels = results.second;

	Scene::activateScene();
}

void EndScene::deactivateScene()
{
	Scene::deactivateScene();
}

void EndScene::keyPressed(unsigned char key, const physx::PxTransform& camera)
{
	switch (toupper(key))
	{
	default:
		break;
	}
}