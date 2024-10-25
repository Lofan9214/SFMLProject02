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

void SpriteGo::setRotation(const float irad)
{
	sprite.setRotation(irad);
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

void SpriteGo::drawrect(sf::RenderWindow& window)
{
	sf::RectangleShape shprec;
	auto sprrect = sprite.getLocalBounds();
	shprec.setPosition(sprrect.getPosition());
	shprec.setSize(sprrect.getSize());

	window.draw(shprec);
}
