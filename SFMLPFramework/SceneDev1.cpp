#include "stdafx.h"
#include "SceneDev1.h"

SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::init()
{
	Scene::init();
}

void SceneDev1::enter()
{

	Scene::enter();
}

void SceneDev1::exit()
{
	Scene::exit();
}

void SceneDev1::update(float dt)
{
	Scene::update(dt);

	if (InputMgr::isKeyDown(sf::Keyboard::Space))
	{
		SceneMgr::Instance().setCurrentScene(SceneIds::Dev2);
	}
}

void SceneDev1::draw(sf::RenderWindow& window)
{
	Scene::draw(window);
}
