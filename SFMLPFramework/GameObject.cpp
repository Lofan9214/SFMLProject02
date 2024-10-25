#include "stdafx.h"
#include "GameObject.h"

GameObject::GameObject(const std::string& iName)
	:name(name), eOrigin(Origins::TL), vOrigin(0.f, 0.f), vScale(1.f, 1.f)
{
}

void GameObject::init()
{
}

void GameObject::release()
{
}

void GameObject::reset()
{
}

void GameObject::update(float dt)
{
}

void GameObject::draw(sf::RenderWindow& window)
{
}

void GameObject::setOrigin(Origins iOrigin)
{
	eOrigin = iOrigin;
	vOrigin = { 0.f,0.f };
}
