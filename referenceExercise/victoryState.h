#pragma once
#include "const.h"
#include "BaseState.h"
#include "sfwdraw.h"

class victoryState : public BaseState
{
public:
	unsigned color, baseColor;
	victoryState()
		: color(CYAN), baseColor(color - 0xff)
	{
	}

	void update();
	void draw();
};