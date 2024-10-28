#pragma once
#include "SpriteGo.h"
class EffectLog :
    public SpriteGo
{
protected:

    sf::Vector2f vGravity = { 0.f,1000.f };
    sf::Vector2f vVelocity;

    float duration = 3.f;
    float timer = 0.f;

public:
    EffectLog(const std::string& texId, const std::string& name = "");
    virtual ~EffectLog();

    void update(float dt) override;

    void fire(const sf::Vector2f& pos, const sf::Vector2f& vel);

};

