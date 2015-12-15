#include "splashState.h"
#include <cstring>
#include <cmath>

void SplashState::update()
{
	float wave = (0xff * (cosf(sfw::getTime() * 4) + 1) / 2);
	
	color = baseColor + wave;

	if (sfw::getKey(KEY_ENTER))
		applicationState = PLAY;
}

void SplashState::draw()
{
	//sfw::drawTexture(background, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, WINDOW_WIDTH, WINDOW_HEIGHT);

	unsigned x, y, s;
	s = 32;
	x = (WINDOW_WIDTH) / 2;
	y = (WINDOW_HEIGHT * 3 / 4);
	drawFontCentered(spriteFont, TITLE, x, y, s, s);

	s = 16;
	y = (WINDOW_HEIGHT * 8 / 16);
	drawFontCentered(spriteFont, "Press Enter To Begin", x, y, s, s);
	drawFontCentered(spriteFont, "Brian Ellis", x, y-20, s, s, GREEN);
}
