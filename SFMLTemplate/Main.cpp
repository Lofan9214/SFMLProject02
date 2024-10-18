#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputMgr.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		InputMgr::Clear();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			InputMgr::UpdateEvent(event);
		}

		if (InputMgr::isKeyDown(sf::Keyboard::Left))
		{
			std::cout << "LeftDown" <<  std::endl;
		}
		if (InputMgr::isKeyUp(sf::Keyboard::Left))
		{
			std::cout << "LeftUp" << std::endl;
		}
		if (InputMgr::isMouseButtonDown(sf::Mouse::Left))
		{
			std::cout << InputMgr::getMousePosition().x << ", " << InputMgr::getMousePosition().y << std::endl;
		}


		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}