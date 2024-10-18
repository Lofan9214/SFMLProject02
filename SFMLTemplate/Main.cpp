#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputMgr.h"
#include "ResourceMgr.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1200, 1200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	ResourceMgr<sf::Texture>::Instance().Load("graphics/player.png");
	sf::Sprite player;
	player.setTexture(ResourceMgr<sf::Texture>::Instance().Get("graphics/player.png"));

	while (window.isOpen())
	{
		sf::Event event;
		InputMgr::Clear();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			switch (event.type)
			{
			case sf::Event::MouseMoved:
				std::cout << InputMgr::getMousePosition(window).x << ", " << InputMgr::getMousePosition(window).y << std::endl;
				break;
			}

			InputMgr::UpdateEvent(event);
		}

		if (InputMgr::isKeyDown(sf::Keyboard::Left))
		{
			std::cout << "LeftDown" << std::endl;
		}
		if (InputMgr::isKeyUp(sf::Keyboard::Left))
		{
			std::cout << "LeftUp" << std::endl;
		}
		if (InputMgr::isMouseButtonDown(sf::Mouse::Left))
		{
			std::cout << InputMgr::getMousePosition(window).x << ", " << InputMgr::getMousePosition(window).y << std::endl;
		}

		window.clear();
		window.draw(shape);
		window.draw(player);
		window.display();
	}

	return 0;
}