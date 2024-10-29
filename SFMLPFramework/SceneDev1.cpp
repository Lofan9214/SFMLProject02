#include "stdafx.h"
#include "SceneDev1.h"
#include "TextGo.h"
#include "CloudGo.h"
#include "BeeGo.h"
#include "TreeGo.h"
#include "PlayerGo.h"

SceneDev1::SceneDev1()
	:Scene(SceneIds::Dev1)
{
}

void SceneDev1::init()
{
	std::cout << "SceneDev1::init()" << std::endl;

	auto obj = addGo(new SpriteGo("graphics/background.png", "BackGround"));

	auto obj2 = addGo(new TextGo("fonts/KOMIKAP_.ttf", "SceneDev1"));

	ResourceMgr<sf::Texture>::Instance().load("graphics/player.png");
	ResourceMgr<sf::Texture>::Instance().load("graphics/rip.png");
	ResourceMgr<sf::Texture>::Instance().load("graphics/axe.png");
	ResourceMgr<sf::Texture>::Instance().load("graphics/tree.png");
	ResourceMgr<sf::Texture>::Instance().load("graphics/branch.png");
	ptrTree = addGo(new TreeGo("Tree"));
	ptrTree->setPosition({ 1920.f * 0.5, 900.f });

	ptrPlayer = addGo(new PlayerGo("Player"));
	ptrPlayer->setPosition({ 1920.f * 0.5, 900.f });


	obj->setOrigin(Origins::MC);
	obj->setPosition({ 960.f, 540.f });

	obj2->setOrigin(Origins::MC);
	obj2->setPosition({ 100.f, 100.f });

	for (int i = 0;i < 3;++i)
	{
		CloudGo* cobj = addGo(new CloudGo("graphics/cloud.png"));
		cobj->setBounds({ -300.f,2200.f });
	}

	for (int i = 0;i < 3;++i)
	{
		BeeGo* bobj = addGo(new BeeGo("graphics/bee.png"));
		bobj->setBounds({ -300.f,2200.f });
	}


	Scene::init();
}

void SceneDev1::enter()
{
	std::cout << "SceneDev1::enter()" << std::endl;

	ResourceMgr<sf::Texture>::Instance().load("graphics/log.png");
	ResourceMgr<sf::Texture>::Instance().load("graphics/tree.png");
	ResourceMgr<sf::Texture>::Instance().load("graphics/branch.png");
	ResourceMgr<sf::Texture>::Instance().load("graphics/background.png");
	ResourceMgr<sf::Texture>::Instance().load("graphics/cloud.png");
	ResourceMgr<sf::Texture>::Instance().load("graphics/bee.png");
	ResourceMgr<sf::Font>::Instance().load("fonts/KOMIKAP_.ttf");

	Scene::enter();
}

void SceneDev1::exit()
{
	std::cout << "SceneDev1::exit()" << std::endl;

	Scene::exit();

	ResourceMgr<sf::Texture>::Instance().unload("graphics/log.png");
	ResourceMgr<sf::Texture>::Instance().unload("graphics/tree.png");
	ResourceMgr<sf::Texture>::Instance().unload("graphics/branch.png");
	ResourceMgr<sf::Texture>::Instance().unload("graphics/background.png");
	ResourceMgr<sf::Texture>::Instance().unload("graphics/cloud.png");
	ResourceMgr<sf::Texture>::Instance().unload("graphics/bee.png");
	ResourceMgr<sf::Font>::Instance().unload("fonts/KOMIKAP_.ttf");
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
