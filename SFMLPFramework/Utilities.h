#pragma once
class Utilities
{
private:
#pragma region 난수생성
	
#pragma endregion

	static sf::Vector2f genOrigin(const sf::FloatRect& objrect, Origins preset);

public:
#pragma region 오리진 설정

	static sf::Vector2f setOrigin(sf::Sprite& obj, Origins preset);
	static sf::Vector2f setOrigin(sf::Text& obj, Origins preset);

#pragma endregion

#pragma region 난수생성

	static std::mt19937 generator;

	static void init();

	static float randFloat(float min, float max);
	static int randInt(int min, int max);
	static float rand0to1();
	static sf::Vector2f randOnUnitCircle();
	static sf::Vector2f randInUnitCircle();

#pragma endregion

#pragma region 삼각함수 관련
	
	const static float PI;

	static float rad2deg(float iRad);
	static float deg2rad(float iDeg);

#pragma endregion
};

