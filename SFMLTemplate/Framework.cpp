#include "stdafx.h"
#include "Framework.h"

void Framework::init(int width, int height, const std::string& strTitle)
{
	window.create(sf::VideoMode(width, height), strTitle);
}

void Framework::dothis()
{
	sf::Event ev;
	sf::Time dt;
	while (window.isOpen())
	{
		dt = clock.restart();
		realDeltaTime = gameDeltaTime = dt.asSeconds();
		gameDeltaTime *= timeScale;
		realTime += realDeltaTime;
		gameTime += gameDeltaTime;

#pragma region �̺�Ʈ ó�� ����
		InputMgr::clear();
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window.close();
			}

			InputMgr::updateEvent(ev);
		}
#pragma endregion �̺�Ʈ ó�� ����

#pragma region ��ü ������Ʈ



#pragma endregion ��ü ������Ʈ

#pragma region ��ü ��ο�
		window.clear();



		window.display();
#pragma endregion ��ü ��ο�
	}
}

void Framework::release()
{
}
