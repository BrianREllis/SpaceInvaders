#pragma once
#include "baseState.h"
#include "sfwdraw.h"
#include "const.h"
class PauseState : public BaseState
{
public:
	unsigned color, baseColor;
	PauseState()
		: color(CYAN), baseColor(color - 0xff)
	{

	}


	void update();
	void draw();

};