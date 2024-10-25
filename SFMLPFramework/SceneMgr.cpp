#include "stdafx.h"
#include "SceneMgr.h"
#include "SceneDev1.h"
#include "SceneDev2.h"

void SceneMgr::init()
{
	vecScenes.push_back(new SceneDev1());
	vecScenes.push_back(new SceneDev2());

	for (auto itScene : vecScenes)
	{
		itScene->init();
	}
	currentScene = defaultScene;
	vecScenes[(int)currentScene]->enter();

}

void SceneMgr::release()
{
	for (auto itscene : vecScenes)
	{
		itscene->release();
		delete itscene;
	}
	vecScenes.clear();
}

void SceneMgr::update(float deltaTime)
{
	vecScenes[(int)currentScene]->update(deltaTime);
}

void SceneMgr::draw(sf::RenderWindow& window)
{
	vecScenes[(int)currentScene]->draw(window);
}

void SceneMgr::setCurrentScene(SceneIds id)
{
	vecScenes[(int)currentScene]->exit();
	currentScene = id;
	vecScenes[(int)currentScene]->enter();
}
