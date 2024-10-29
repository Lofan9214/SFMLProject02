#pragma once
#include "GameObject.h"
class UiTimebar :
    public GameObject
{
protected:

    sf::RectangleShape shpRect;
    sf::Vector2f vMaxSize;
    sf::Vector2f vCurrentSize;

public:
    UiTimebar(const std::string& name = "");
    virtual ~UiTimebar() = default;

    void setPosition(const sf::Vector2f& pos) override;
    void setOrigin(Origins preset) override;
    void setOrigin(const sf::Vector2f& neworigin) override;
    void setScale(const sf::Vector2f& iscale) override;

    void reset() override;

    void draw(sf::RenderWindow& window) override;

    float getValue() const { return vCurrentSize.x / vMaxSize.x; }
    void setValue(float value);

    void setTimebar(const sf::Vector2f size, const sf::Color& color);

};

