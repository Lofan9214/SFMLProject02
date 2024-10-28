#pragma once
#include "SpriteGo.h"
class BranchGo :
    public SpriteGo
{
protected:
    Sides eSide = Sides::None;

public:
    BranchGo(const std::string& texId, const std::string& name = "");
    virtual ~BranchGo() = default;

    void reset() override;

    void setSide(Sides side);
    Sides getSide() { return eSide; }

};

