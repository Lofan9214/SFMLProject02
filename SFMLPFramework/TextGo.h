#pragma once
#include "GameObject.h"
class TextGo :
	public GameObject
{
protected:
	sf::Text text;
	std::string fontId;

	TextGo() = delete;
public:
	~TextGo() = default;
	TextGo(const std::string& fontId, const std::string& name = "");

	void setOrigin(Origins preset) override;
	void 

};

