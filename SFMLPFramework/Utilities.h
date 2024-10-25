#pragma once
class Utilities
{
private:
#pragma region 난수생성
	static std::mt19937 generator;
	
#pragma endregion 난수생성

	static sf::Vector2f genOrigin(const sf::FloatRect& objrect, Origins preset);

public:
#pragma region 오리진 설정

	static sf::Vector2f SetOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f SetOrigin(sf::Text& obj, Origins preset);

#pragma endregion 오리진 설정

#pragma region 난수생성

	const static float PI;
	static void init();

	static float randFloat(float min, float max);
	static int randInt(int min, int max);
	static float rand0to1();
	static sf::Vector2f randOnUnitCircle();
	static sf::Vector2f randInUnitCircle();

#pragma endregion 난수생성

};

