#include "stdafx.h"
#include "BranchGo.h"

BranchGo::BranchGo(const std::string& texId, const std::string& name)
	:SpriteGo(texId, name)
{
}

void BranchGo::reset()
{
	SpriteGo::reset();
	setSide(Sides::Rand);
}

void BranchGo::setSide(Sides side)
{
	eSide = side;
	switch (eSide)
	{
	case Sides::Left:
		bActive = true;
		setFlipX(true);
		break;
	case Sides::Right:
		bActive = true;
		setFlipX(false);
		break;
	case Sides::Rand:
		setSide((Sides)Utilities::randInt((int)Sides::Left, (int)Sides::None));
		break;
	default:
		bActive = false;
		break;
	}

}
