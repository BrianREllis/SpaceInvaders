#pragma once
#include "baseState.h"
#include "sfwdraw.h"
#include "const.h"
class SplashState : public BaseState
{
public:
	unsigned color, baseColor;
	SplashState()
		: color(CYAN), baseColor(color - 0xff)
	{

	}
	

	void update();
	void draw();

};