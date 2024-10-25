#pragma once

class GameObject
{
protected:
	bool bActive = true;
	bool bDraw = true;

	std::string name;

	Origins eOrigin;
	sf::Vector2f vOrigin;
	sf::Vector2f vPosition;
	float fRotation;
	sf::Vector2f vScale;

	GameObject(const GameObject&) = delete;
	GameObject& operator=(const GameObject&) = delete;

public:
	GameObject(const std::string& iName = "");
	virtual ~GameObject() = default;

	virtual void init();
	virtual void release();

	virtual void reset();

	virtual void update(float dt);
	virtual void draw(sf::RenderWindow& window);

	bool getActive() const { return bActive; }
	void setActive(bool iActive) { bActive = iActive; }

	bool getDraw() const { return bDraw; }
	void setDraw(bool iDraw) { bDraw = iDraw; }

	const std::string& getName() { return name; }
	void setName(const std::string& iName) { name = iName; }

	sf::Vector2f getOrigin() const { return vOrigin; }
	void setOrigin(Origins iOrigin);
	virtual void setOrigin(const sf::Vector2f& iOrigin)
	{
		vOrigin = iOrigin;
		eOrigin = Origins::Custom;
	}

	sf::Vector2f getPosition() const { return vPosition; }
	virtual void setPosition(const sf::Vector2f& iPosition) { vPosition = iPosition; }

	float getRotation() const { return fRotation; }
	void setRotation(float iRotation) { fRotation = iRotation; }

	sf::Vector2f getScale() const { return vScale; }
	void setScale(const sf::Vector2f iScale) { vScale = iScale; }

};

