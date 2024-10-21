#include "stdafx.h"
#include "SpriteGo.h"

SpriteGo::SpriteGo(const std::string& iTexId)
	:textureId(iTexId)
{
	
}

void SpriteGo::setPosition(const sf::Vector2f& iPos)
{
	GameObject::setPosition(iPos);
	sprite.setPosition(iPos);
}

void SpriteGo::reset()
{
	auto& texResMgr = TEXTUREMGR;
	sprite.setTexture(texResMgr.Get(textureId));
}

void SpriteGo::draw(sf::RenderWindow& window)
{
	GameObject::draw(window);
	window.draw(sprite);
}
