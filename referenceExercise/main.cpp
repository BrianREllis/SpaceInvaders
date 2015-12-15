#include <iostream>
#include <cassert>
#include "vec2.h"
#include "sfwdraw.h"
#include "gamestate.h"
#include "splashState.h"
#include "pauseState.h"
#include "victoryState.h"

unsigned spritePlayer;
unsigned spriteEnemy;
unsigned spriteParticle;
unsigned spriteSpace;
unsigned spriteFont;

STATE applicationState = SPLASH;

int main()
{
	
	sfw::initContext(WINDOW_WIDTH, WINDOW_HEIGHT, "The Absolute Greatest Game (GOTY Edition)");

	//Player player(400, 400);
	//Bullet bullet(400, 100, 10);

	spritePlayer   = sfw::loadTextureMap("../Images/rocket.png");
	spriteEnemy    =  sfw::loadTextureMap("../Images/ufo.png");
	spriteParticle = sfw::loadTextureMap("../Images/bullet.png");
	spriteFont     = sfw::loadTextureMap("../Images/fontmap.png", 16, 16);
	//got const next

	GameState gs;
	SplashState ss;
	PauseState ps;
	victoryState vs;


	while (sfw::stepContext() && !sfw::getKey(KEY_ESCAPE))
	{
		switch (applicationState)
		{
		case SPLASH:
			ss.update();
			ss.draw();
			break;
		case PLAY:
			applicationState = GAME;
			break;
		case GAME:
			gs.update();
			gs.draw();
			break;
		case PAUSE:
			gs.draw();
			ps.update();
			ps.draw();
			break;
		case VICTORY:
			vs.update();
			vs.draw();
	
		default:
			break;
		}

		//sfw::drawCircle(400, 300, 20);
	}
	sfw::termContext();
	return 0;
	//int t1 = 0,
	//	t2 = 0,
	//	t3 = 0;
	//passByVal(t1);
	//passByRef(t2);
	//passByPtr(&t3);
	//vec2 a = {1, 3 };
	//vec2 b = {3, 1 };
	//assert((a + b) == b);

	system("pause");
}

void drawFontCentered(unsigned sprite, const char* text, unsigned x, unsigned y, unsigned w,
						unsigned h, unsigned color)
{
	x -= strlen(text) * w / 2;
	sfw::drawString(spriteFont, text, x, y, w, h, 0, 0, color);
}