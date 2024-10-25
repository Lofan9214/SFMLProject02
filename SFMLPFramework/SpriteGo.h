#pragma once
class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;

public:
	SpriteGo() = default;
	~SpriteGo() = default;

	SpriteGo(const std::string& iTexId, const std::string& name = "");

	void setPosition(const sf::Vector2f& iPos) override;
	void setRotation(const float irad);

	void reset() override;
	void draw(sf::RenderWindow& window) override;
	void drawrect(sf::RenderWindow& window);
};

