#pragma once
class Scene
{
protected:
	std::list<GameObject*> lstGameObj;
	
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;
public:
	Scene();
	virtual ~Scene();
};

