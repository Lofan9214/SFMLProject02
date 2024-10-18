#include "InputMgr.h"

std::unordered_map<int, std::bitset<3>> InputMgr::mapInput;

void InputMgr::Clear()
{
	std::bitset<3> remover = 0;
	remover[(int)State::Pressing] = true;

	for (auto& it : mapInput)
	{
		it.second &= remover;
	}
}

void InputMgr::UpdateEvent(const sf::Event& ev)
{
	std::unordered_map<int, std::bitset<3>>::iterator itInput = mapInput.end();
	std::bitset<3> setter = 0;

	switch (ev.type)
	{
	case sf::Event::KeyPressed:
		itInput = mapInput.find(ev.key.code);
		setter[(int)State::Down] = true;
		setter[(int)State::Pressing] = true;

		if (itInput != mapInput.end())
		{
			itInput->second = setter;
		}
		else
		{
			mapInput.insert({ (int)(ev.key.code), setter });
		}
		break;
	case sf::Event::KeyReleased:
		itInput = mapInput.find(ev.key.code);
		setter[(int)State::Release] = true;

		if (itInput != mapInput.end())
		{
			itInput->second = setter;
		}
		else
		{
			mapInput.insert({ (int)(ev.key.code), setter });
		}
		break;
	case sf::Event::MouseButtonPressed:
		itInput = mapInput.find(-(ev.mouseButton.button + 1));
		setter[(int)State::Down] = true;
		setter[(int)State::Pressing] = true;

		if (itInput != mapInput.end())
		{
			itInput->second = setter;
		}
		else
		{
			mapInput.insert({ -(ev.mouseButton.button + 1), setter });
		}
		break;
	case sf::Event::MouseButtonReleased:
		itInput = mapInput.find(-(ev.mouseButton.button + 1));
		setter[(int)State::Release] = true;

		if (itInput != mapInput.end())
		{
			itInput->second = setter;
		}
		else
		{
			mapInput.insert({ -(ev.mouseButton.button + 1), setter });
		}
		break;
	}
}

bool InputMgr::isKeyDown(const sf::Keyboard::Key& key)
{
	auto it = mapInput.find(key);
	if (it == mapInput.end())
	{
		return false;
	}
	return it->second[(int)State::Down];
}

bool InputMgr::isKeyPressing(const sf::Keyboard::Key& key)
{
	auto it = mapInput.find(key);
	if (it == mapInput.end())
	{
		return false;
	}
	return it->second[(int)State::Pressing];
}

bool InputMgr::isKeyUp(const sf::Keyboard::Key& key)
{
	auto it = mapInput.find(key);
	if (it == mapInput.end())
	{
		return false;
	}
	return it->second[(int)State::Release];
}

bool InputMgr::isMouseButtonDown(const sf::Mouse::Button& btn)
{
	auto it = mapInput.find(-(btn + 1));
	if (it == mapInput.end())
	{
		return false;
	}
	return it->second[(int)State::Down];
}

bool InputMgr::isMouseButtonPressing(const sf::Mouse::Button& btn)
{
	auto it = mapInput.find(-(btn + 1));
	if (it == mapInput.end())
	{
		return false;
	}
	return it->second[(int)State::Pressing];
}

bool InputMgr::isMouseButtonUp(const sf::Mouse::Button& btn)
{
	auto it = mapInput.find(-(btn + 1));
	if (it == mapInput.end())
	{
		return false;
	}
	return it->second[(int)State::Release];
}

sf::Vector2i InputMgr::getMousePosition(const sf::Window& curWindow)
{
	return sf::Mouse::getPosition(curWindow);
}


