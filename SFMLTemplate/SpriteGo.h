#pragma once
class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;

public:
	SpriteGo() = default;
	~SpriteGo() = default;

	SpriteGo(const std::string& iTexId);

	void setPosition(const sf::Vector2f& iPos) override;

	void reset() override;
	void draw(sf::RenderWindow& window) override;
};

