#include "stdafx.h"
#include "UiScore.h"

UiScore::UiScore(const std::string& fontId, const std::string& name)
	:TextGo(fontId, name)
{
}

void UiScore::reset()
{
	TextGo::reset();
	setScore(0);
}

void UiScore::setScore(int iScore)
{
	score = iScore;
	text.setString(strFormat + std::to_string(score));
}
