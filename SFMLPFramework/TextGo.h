#pragma once
#include "GameObject.h"
class TextGo :
	public GameObject
{
protected:
	sf::Text text;
	std::string strFontId;

	TextGo() = delete;

	TextGo(const TextGo&) = delete;
	TextGo& operator=(const TextGo&) = delete;
public:
	~TextGo() = default;
	TextGo(const std::string& fontId, const std::string& name = "");

	void reset() override;
	void draw(sf::RenderWindow& window) override;

	void setOrigin(Origins preset) override;
	void setOrigin(const sf::Vector2f& neworigin) override;
	void setPosition(const sf::Vector2f& iPos) override;

	void setString(const std::string& strChange);
	void setCharSize(unsigned int iSize);
	void setTextColor(const sf::Color& iColor);
};

