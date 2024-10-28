#include "stdafx.h"
#include "BranchGo.h"

BranchGo::BranchGo(const std::string& texId, const std::string& name)
	:SpriteGo(texId, name)
{
}

void BranchGo::reset()
{
	SpriteGo::reset();
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
		setSide((Sides)Utilities::randInt((int)Sides::None, (int)Sides::Right));
		break;
	default:
		bActive = false;
		break;
	}

}
