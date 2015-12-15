#include "pauseState.h"
#include "sfwdraw.h"


void PauseState::update()
{
	if (sfw::getKey(KEY_TAB))
		applicationState = GAME;
	if(sfw::getKey('Q'))
		applicationState = VICTORY;
}

void PauseState::draw()
{
	unsigned x, y, s;

	s = 24;
	x = (WINDOW_WIDTH) / 2;
	y = (WINDOW_HEIGHT * 3 / 4);
	drawFontCentered(spriteFont, "PAUSED", x, y, s, s);

	s = 18;
	y = (WINDOW_HEIGHT * 5 / 8);
	drawFontCentered(spriteFont, "Press  Tab To Continue", x, y, s, s);
	drawFontCentered(spriteFont, "Press Q to Quit", x, y - 18, s, s);
}
