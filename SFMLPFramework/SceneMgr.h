#pragma once
#include "Scene.h"

class SceneMgr : public Singleton<SceneMgr>
{
	friend Singleton<SceneMgr>;
protected:
	std::vector<Scene*> vecScenes;

	SceneIds defaultScene = SceneIds::Dev1;
	SceneIds currentScene;

	SceneMgr() = default;
	virtual ~SceneMgr() = default;

	SceneMgr(const SceneMgr&) = delete;
	SceneMgr& operator=(const SceneMgr&) = delete;

public:

	void init();
	void release();

	void update(float deltaTime);
	void draw(sf::RenderWindow& window);

	SceneIds getCurrentScene() const { return currentScene; }
	void setCurrentScene(SceneIds id);

};

