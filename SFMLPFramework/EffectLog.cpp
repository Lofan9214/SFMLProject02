#include "stdafx.h"
#include "EffectLog.h"

EffectLog::EffectLog(const std::string& texId, const std::string& name)
	:SpriteGo(texId,name)
{
}

EffectLog::~EffectLog()
{
}

void EffectLog::update(float dt)
{
	timer += dt;
	if (timer > duration)
	{
		bActive = false;
		return;
	}
	vVelocity += vGravity * dt;
	setPosition(vPosition + vVelocity * dt);
}

void EffectLog::fire(const sf::Vector2f& pos, const sf::Vector2f& vel)
{
	bActive = true;
	vVelocity = vel;
	vPosition = pos;
	timer = 0.f;
}
