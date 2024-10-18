#pragma once
#include <bitset>
#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Mouse.hpp>

class InputMgr
{
private:
	enum class State
	{
		Release,
		Down,
		Pressing,
	};
	static std::unordered_map<int, std::bitset<3>> mapInput;
public:
	static void Clear();
	static void UpdateEvent(const sf::Event& ev);

	static bool isKeyDown(const sf::Keyboard::Key& key);
	static bool isKeyPressing(const sf::Keyboard::Key& key);
	static bool isKeyUp(const sf::Keyboard::Key& key);

	static bool isMouseButtonDown(const sf::Mouse::Button& btn);
	static bool isMouseButtonPressing(const sf::Mouse::Button& btn);
	static bool isMouseButtonUp(const sf::Mouse::Button& btn);

	static sf::Vector2i getMousePosition();
};

