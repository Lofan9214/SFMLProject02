#pragma once
#include "TextGo.h"
class UiScore :
    public TextGo
{
protected:
    std::string strFormat = "SCORE : ";
    int score = 0;

    UiScore(const UiScore&) = delete;
    UiScore& operator=(const UiScore&) = delete;
public:
    UiScore(const std::string& fontId, const std::string& name = "");
    virtual ~UiScore() = default;

    void reset() override;
    void setScore(int iScore);

};

