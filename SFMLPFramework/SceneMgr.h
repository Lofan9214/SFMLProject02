#pragma once
#include "Scene.h"

class SceneMgr : public Singleton<SceneMgr>
{
protected:
	std::vector<Scene*> scenes;

public:
	SceneMgr() = default;
	virtual ~SceneMgr() = default;

	void init();
	void dothis();
	void release();
};

