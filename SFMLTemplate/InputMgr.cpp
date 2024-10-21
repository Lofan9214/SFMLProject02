#include "InputMgr.h"

std::vector<std::bitset<3>> InputMgr::vecInput(sf::Keyboard::KeyCount + sf::Mouse::ButtonCount, 0);

void InputMgr::clear()
{
	std::bitset<3> remover = 0;
	remover[(int)State::Pressing] = true;

	for (auto& it : vecInput)
	{
		it &= remover;
	}
}

void InputMgr::updateEvent(const sf::Event& ev)
{
	std::vector<std::bitset<3>>::iterator itInput = vecInput.end();
	std::bitset<3> setter = 0;
	int idx;

	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		idx = ev.key.code;
		itInput = vecInput.begin() + idx;
		setter[(int)State::Down] = true;
		setter[(int)State::Pressing] = true;

		*itInput = setter;
	case sf::Event::KeyReleased:
		idx = ev.key.code;
		itInput = vecInput.begin() + idx;
		setter[(int)State::Release] = true;

		*itInput = setter;
		break;
	case sf::Event::MouseButtonPressed:
		idx = sf::Keyboard::KeyCount + ev.mouseButton.button;
		itInput = vecInput.begin() + idx;
		setter[(int)State::Down] = true;
		setter[(int)State::Pressing] = true;

		*itInput = setter;

		break;
	case sf::Event::MouseButtonReleased:
		idx = sf::Keyboard::KeyCount + ev.mouseButton.button;
		itInput = vecInput.begin() + idx;
		setter[(int)State::Release] = true;
		*itInput = setter;
		break;
	}
}

bool InputMgr::isKeyDown(const sf::Keyboard::Key& key)
{
	return (*(vecInput.begin() + key))[(int)State::Down];
}

bool InputMgr::isKeyPressing(const sf::Keyboard::Key& key)
{
	return (*(vecInput.begin() + key))[(int)State::Pressing];
}

bool InputMgr::isKeyUp(const sf::Keyboard::Key& key)
{
	return (*(vecInput.begin() + key))[(int)State::Release];
}

bool InputMgr::isMouseButtonDown(const sf::Mouse::Button& btn)
{
	return (*(vecInput.begin() + sf::Keyboard::KeyCount + btn))[(int)State::Down];
}

bool InputMgr::isMouseButtonPressing(const sf::Mouse::Button& btn)
{
	return (*(vecInput.begin() + sf::Keyboard::KeyCount + btn))[(int)State::Pressing];
}

bool InputMgr::isMouseButtonUp(const sf::Mouse::Button& btn)
{
	return (*(vecInput.begin() + sf::Keyboard::KeyCount + btn))[(int)State::Release];
}

sf::Vector2i InputMgr::getMousePosition(const sf::Window& curWindow)
{
	return sf::Mouse::getPosition(curWindow);
}


