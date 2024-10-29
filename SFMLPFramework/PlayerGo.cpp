#include "stdafx.h"
#include "PlayerGo.h"

PlayerGo::PlayerGo(const std::string& iName)
	:GameObject(iName)
{
}

void PlayerGo::setSide(Sides iSide)
{
	eSide = iSide;
	sf::Vector2f vNewPos = vPosition + vPlayerLocalPos[(int)eSide];

	if (eSide == Sides::Left)
	{
		setScale({ -1.f,1.f });
	}
	else
	{
		setScale({ 1.f,1.f });
	}

	sprPlayer.setPosition(vNewPos);
	sprAxe.setPosition(vNewPos + vAxeLocalPos);
	sprRip.setPosition(vNewPos + vRipLocalPos);
}

void PlayerGo::onDie()
{
	bAlive = false;
	bChopping = false;
}

void PlayerGo::setPosition(const sf::Vector2f& iPos)
{
	vPosition = iPos;
	setSide(eSide);
}

void PlayerGo::setScale(const sf::Vector2f& iScale)
{
	vScale = iScale;
	sprPlayer.setScale(vScale);
	sprAxe.setScale({ -vScale.x,vScale.y });
	sprRip.setScale({ abs(vScale.x) ,vScale.y });
}

void PlayerGo::setOrigin(Origins iOrigin)
{
	eOrigin = iOrigin;
	if (eOrigin < Origins::Custom)
	{
		vOrigin = Utilities::setOrigin(sprPlayer, eOrigin);
	}
}

void PlayerGo::setOrigin(const sf::Vector2f& iVOrigin)
{
	eOrigin = Origins::Custom;
	vOrigin = iVOrigin;
	sprPlayer.setOrigin(vOrigin);
}

void PlayerGo::init()
{
	GameObject::init();
	sprPlayer.setTexture(ResourceMgr<sf::Texture>::Instance().get(strTexIdPlayer));
	setOrigin(Origins::BC);

	sprAxe.setTexture(ResourceMgr<sf::Texture>::Instance().get(strTexIdAxe));
	sprAxe.setOrigin(vAxeOrigin);

	sprRip.setTexture(ResourceMgr<sf::Texture>::Instance().get(strTexIdRip));
	Utilities::setOrigin(sprRip, Origins::BC);
}

void PlayerGo::release()
{
}

void PlayerGo::reset()
{
	bAlive = true;
	bChopping = false;

	setPosition(vPosition);
	setSide(Sides::Right);
}

void PlayerGo::update(float dt)
{
	if (InputMgr::isKeyDown(sf::Keyboard::Num2))
	{
		reset();
	}
	if (!bAlive)
	{
		return;
	}

	if (InputMgr::isKeyDown(sf::Keyboard::Num1))
	{
		onDie();
	}
	if (InputMgr::isKeyDown(sf::Keyboard::Left))
	{
		setSide(Sides::Left);
		bChopping = true;
	}
	if (InputMgr::isKeyDown(sf::Keyboard::Right))
	{
		setSide(Sides::Right);
		bChopping = true;
	}
	if (InputMgr::isKeyUp(sf::Keyboard::Left))
	{
		bChopping = false;
	}
	if (InputMgr::isKeyUp(sf::Keyboard::Right))
	{
		bChopping = false;
	}
}

void PlayerGo::draw(sf::RenderWindow& window)
{
	if (bAlive)
	{
		window.draw(sprPlayer);
		if (bChopping)
		{
			window.draw(sprAxe);
		}
	}
	else
	{
		window.draw(sprRip);
	}
}
