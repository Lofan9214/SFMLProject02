#pragma once
class SpriteGo : public GameObject
{
protected:
	sf::Sprite sprite;
	std::string textureId;

public:
	~SpriteGo() = default;

	SpriteGo(const std::string& iTexId, const std::string& name = "");
	void setResourceId(const std::string& id) { textureId = id; }

	void setPosition(const sf::Vector2f& iPos) override;
	void setRotation(const float irad);

	void setOrigin(Origins preset) override;
	void setOrigin(const sf::Vector2f& neworigin) override;

	void setFlipX(bool flipX) override;
	void setFlipY(bool flipY) override;

	void reset() override;
	void draw(sf::RenderWindow& window) override;
	void drawrect(sf::RenderWindow& window);
};

