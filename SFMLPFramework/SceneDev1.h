#pragma once
#include "Scene.h"
class SceneDev1 :
	public Scene
{
protected:

	SceneDev1(const SceneDev1&) = delete;
	SceneDev1& operator=(const SceneDev1&) = delete;
public:
	SceneDev1();
	~SceneDev1() = default;
	
	void init() override;
	void enter() override;
	void exit() override;

	void update(float dt) override;
	void draw(sf::RenderWindow& window) override;
};

