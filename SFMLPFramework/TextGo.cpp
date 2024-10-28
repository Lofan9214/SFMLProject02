#include "stdafx.h"
#include "TextGo.h"

TextGo::TextGo(const std::string& fontId, const std::string& name)
	:strFontId(fontId), GameObject(name)
{
}

void TextGo::reset()
{
	text.setFont(ResourceMgr<sf::Font>::Instance().Get(strFontId));
	setOrigin(eOrigin);
}

void TextGo::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
	window.draw(text);
}

void TextGo::setOrigin(Origins preset)
{
	if (preset < Origins::Custom)
	{
		eOrigin = preset;
		vOrigin = Utilities::SetOrigin(text, preset);
	}
}

void TextGo::setOrigin(const sf::Vector2f& vNewOrigin)
{
	eOrigin = Origins::Custom;
	vOrigin = vNewOrigin;
	text.setOrigin(vOrigin);
}

void TextGo::setString(const std::string& strChange)
{
	text.setString(strChange);
}