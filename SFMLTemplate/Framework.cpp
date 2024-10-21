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

#pragma region 이벤트 처리 루프
		InputMgr::clear();
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window.close();
			}

			InputMgr::updateEvent(ev);
		}
#pragma endregion 이벤트 처리 루프

#pragma region 객체 업데이트



#pragma endregion 객체 업데이트

#pragma region 객체 드로우
		window.clear();



		window.display();
#pragma endregion 객체 드로우
	}
}

void Framework::release()
{
}
