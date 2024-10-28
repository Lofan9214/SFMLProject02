#pragma once
#include "SpriteGo.h"
class CloudGo :
    public SpriteGo
{
protected:
	sf::Vector2f vRangeSpeed;
	sf::Vector2f vRangeScale;
	sf::Vector2f vSpeed;
	sf::Vector2f vBounds;
	float fDirection = 0.f;

public:
	CloudGo(const std::string& texId, const std::string& name = "");
	virtual ~CloudGo() = default;

	void setRangeSpeed(const sf::Vector2f& rngSpeed) { vRangeSpeed = rngSpeed; }
	void setRangeScale(const sf::Vector2f& rngScale) { vRangeScale = rngScale; }
	void setSpeed(const sf::Vector2f& speed) { vSpeed = speed; }
	void setBounds(const sf::Vector2f& bounds) { vBounds = bounds; }

	void reset() override;
	void update(float dt) override;
};

