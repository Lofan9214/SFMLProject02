#include "stdafx.h"
#include "SpriteGo.h"

SpriteGo::SpriteGo(const std::string& iTexId, const std::string& name)
	:textureId(iTexId), GameObject(name)
{

}

void SpriteGo::setPosition(const sf::Vector2f& iPos)
{
	GameObject::setPosition(iPos);
	sprite.setPosition(iPos);
}

void SpriteGo::setRotation(const float irad)
{
	fRotation = irad;
	sprite.setRotation(irad * 180 / Utilities::PI);
}

void SpriteGo::setOrigin(Origins preset)
{
	if (preset < Origins::Custom)
	{
		eOrigin = preset;
		vOrigin = Utilities::SetOrigin(sprite, preset);
	}
}

void SpriteGo::setOrigin(const sf::Vector2f& neworigin)
{
	eOrigin = Origins::Custom;
	sprite.setOrigin(neworigin);
}

void SpriteGo::setFlipX(bool flipX)
{
	GameObject::setFlipX(flipX);
	sprite.setScale(vScale);
}

void SpriteGo::setFlipY(bool flipY)
{
	GameObject::setFlipX(flipY);
	sprite.setScale(vScale);
}

void SpriteGo::reset()
{
	auto& texResMgr = ResourceMgr<sf::Texture>::Instance();
	sprite.setTexture(texResMgr.Get(textureId));
	sprite.setScale(vScale);
	setOrigin(eOrigin);
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
