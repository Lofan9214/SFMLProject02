#pragma once

class Framework : public Singleton<Framework>
{
	friend Singleton<Framework>;

protected:

	Framework() = default;
	virtual ~Framework() = default;

	Framework(const Framework& fw) = delete;
	Framework& operator=(const Framework& fw) = delete;

	sf::RenderWindow window;

	sf::Clock clock;
	float timeScale = 1.f;

	float gameTime = 0.f;
	float gameDeltaTime = 0.f;
	float realTime = 0.f;
	float realDeltaTime = 0.f;

public:

	float getGameTime() const { return gameTime; }
	float getGameDeltaTime() const { return gameDeltaTime; }
	float getRealTime() const { return realTime; }
	float getRealDeltaTime() const { return realDeltaTime; }

	void setTimeScale(float iTimeScale) { timeScale = iTimeScale; }
	float getTimeScale() const { return timeScale; }

	virtual void init(int width, int height, const std::string& strTitle);
	virtual void dothis();
	virtual void release();
};

#define FRAMEWORK (Framework::Instance())