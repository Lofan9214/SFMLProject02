#include "stdafx.h"
#include "Utilities.h"

std::mt19937 Utilities::generator;
const float Utilities::PI = acosf(-1);

sf::Vector2f Utilities::genOrigin(const sf::FloatRect& objrect, Origins preset)
{
	sf::Vector2f newOrigin;

	newOrigin.x = objrect.left + objrect.width * ((int)preset % 3) * 0.5f;
	newOrigin.y = objrect.top + objrect.height * ((int)preset / 3) * 0.5f;

	return newOrigin;
}

sf::Vector2f Utilities::SetOrigin(sf::Sprite& obj, Origins preset)
{
	sf::Vector2f neworigin = genOrigin(obj.getLocalBounds(), preset);
	obj.setOrigin(neworigin);
	return neworigin;
}

sf::Vector2f Utilities::SetOrigin(sf::Text& obj, Origins preset)
{
	sf::Vector2f neworigin = genOrigin(obj.getLocalBounds(), preset);
	obj.setOrigin(neworigin);
	return neworigin;
}

void Utilities::init()
{
	std::random_device rd;
	generator.seed(rd());
}

float Utilities::randFloat(float min, float max)
{
	std::uniform_real_distribution<> dist(min, max);
	return dist(generator);
}

int Utilities::randInt(int min, int max)
{
	std::uniform_int_distribution<> dist(min, max);
	return dist(generator);
}

float Utilities::rand0to1()
{
	std::uniform_real_distribution<> dist(0.f, 1.f);
	return dist(generator);
}

sf::Vector2f Utilities::randOnUnitCircle()
{
	float rad = randFloat(0.f, PI * 2.f);
	return sf::Vector2f(std::cosf(rad), std::sinf(rad));
}

sf::Vector2f Utilities::randInUnitCircle()
{
	return randOnUnitCircle() * rand0to1();
}

float Utilities::rad2deg(float iRad)
{
	return iRad * 180.f / Utilities::PI;
}

float Utilities::deg2rad(float iDeg)
{
	return iDeg / 180.f * Utilities::PI;
}
