#pragma once
#include "SpriteGo.h"
class BeeGo :
	public SpriteGo
{
protected:
	sf::Vector2f vRangeSpeed;
	sf::Vector2f vRangeScale;
	sf::Vector2f vSpeed;
	sf::Vector2f vBounds;
	float fDirection = 0.f;

public:
	BeeGo(const std::string& texId, const std::string& name = "");
	virtual ~BeeGo() = default;

	void setRangeSpeed(const sf::Vector2f& rngSpeed) { this->vRangeSpeed = rngSpeed; }
	void setSpeed(const sf::Vector2f& speed) { this->vSpeed = speed; }
	void setBounds(const sf::Vector2f& bound) { this->vBounds = bound; }
	void setScale(const sf::Vector2f& scale) { this->vRangeScale = scale; }

	void reset() override;
	void update(float dt) override;
};

