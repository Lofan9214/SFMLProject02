#include "stdafx.h"
#include "Scene.h"

Scene::Scene(SceneIds iSceneId)
	:eSceneId(iSceneId)
{
}

void Scene::init()
{
	for (auto obj : lstGameObj)
	{
		obj->init();
	}
}

void Scene::release()
{
	for (auto obj : lstGameObj)
	{
		obj->release();
		delete obj;
	}
	lstGameObj.clear();
}

void Scene::enter()
{
	for (auto obj : lstGameObj)
	{
		obj->reset();
	}
}

void Scene::exit()
{
}

void Scene::update(float dt)
{
	for (auto obj : lstGameObj)
	{
		if (!obj->getActive())
		{
			continue;
		}
		obj->update(dt);
	}
}

void Scene::draw(sf::RenderWindow& window)
{
	for (auto obj : lstGameObj)
	{
		if (!obj->getDraw())
		{
			continue;
		}
		obj->draw(window);
	}

}

void Scene::removeGo(GameObject* obj)
{
	if (find(lstGameObj.begin(), lstGameObj.end(), obj)!=lstGameObj.end())
	{
		delete obj;
		lstGameObj.remove(obj);
	}
}

GameObject* Scene::findGo(const std::string& name)
{
	for (auto obj : lstGameObj)
	{
		if (obj->getName() == name)
		{
			return obj;
		}
	}
	return nullptr;
}

int Scene::FindGoAll(const std::string& name, std::list<GameObject*>& list)
{
	int cnt = 0;

	if (list.size() > 0)
	{
		for (auto obj : list)
		{
			obj->release();
		}
		list.clear();
	}

	for (auto obj : lstGameObj)
	{
		if (obj->getName() == name)
		{
			++cnt;
			list.push_back(obj);
		}
	}

	return cnt;
}


