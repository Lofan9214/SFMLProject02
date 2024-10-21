#pragma once

class GameObject
{
protected:
	bool bActive = true;
	sf::Vector2f vfPosition;

	GameObject(const GameObject& obj) = delete;
	GameObject& operator=(const GameObject& obj) = delete;

public:

	GameObject() = default;
	virtual ~GameObject() = default;

	bool isActive() const { return bActive; }
	void setActive(bool iActive) { bActive = iActive; }

	sf::Vector2f getPosition() const { return vfPosition; }
	virtual void setPosition(const sf::Vector2f& iPosition) { vfPosition = iPosition; }

	virtual void init();
	virtual void dothis();

	virtual void reset();

	virtual void update(float dt);
	virtual void draw(sf::RenderWindow& window);
};

