#pragma once

#define WINDOW_WIDTH 400
#define WINDOW_HEIGHT 600

#define BOUNDS_TOP WINDOW_HEIGHT-60
#define BOUNDS_BOTTOM 60
#define BOUNDS_LEFT 80
#define BOUNDS_RIGHT WINDOW_WIDTH-80

#define TITLE "Space In-Vader"

class GameState;

extern unsigned spritePlayer;
extern unsigned spriteEnemy;
extern unsigned spriteParticle;
extern unsigned spriteSpace;
extern unsigned spriteFont;

enum STATE { SPLASH, PLAY, GAME, VICTORY, PAUSE};

extern STATE applicationState;

void drawFontCentered(unsigned sprite, const char* text, unsigned x,
	unsigned y, unsigned w, unsigned h, unsigned color = 0xffffffff);

