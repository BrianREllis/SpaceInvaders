#include "victorystate.h"
#include "const.h"
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <cmath>

void victoryState::update()
{
	float wave = (0xff * (cosf(sfw::getTime() * 4) + 1) / 2);
	color = baseColor + wave;

	if (sfw::getKey('R'))
		applicationState = SPLASH;
}

void victoryState::draw()
{
	sfw::drawTexture(spriteSpace, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2,
		WINDOW_WIDTH, WINDOW_HEIGHT, 0, true, 0, 0x88888888);

	unsigned x, y, s;

	s = 24;
	x = (WINDOW_WIDTH) / 2;
	y = WINDOW_HEIGHT * 3 / 4;
	drawFontCentered(spriteFont, "You Did A Thing", x, y, s, s);

	s = 18;
	y = WINDOW_HEIGHT * 5 / 8;
	drawFontCentered(spriteFont, "Press R to Return to Main", x, y, s, s, color);

	std::fstream fin("scores.dat", std::ios_base::in);
	std::vector<unsigned> scores;
	while (!fin.eof())
	{
		unsigned t;
		fin >> t;
		scores.push_back(t);
	}

	scores.pop_back();
	fin.close();


	s = 32 + sinf(sfw::getTime() * 6) * 6;
	y = WINDOW_HEIGHT / 2;
	sfw::drawString(spriteFont, std::to_string(scores[scores.size() - 1]).c_str(), x + sin(sfw::getTime()) * 10, y, s, s, 0, 0, GREEN);

	

	s = 18;
	y = WINDOW_HEIGHT / 2 - scores.size() * s;
	for (int i = scores.size() - 2; i >= 0 && scores.size()-i < 12; --i)
	{
		sfw::drawString(spriteFont, std::to_string(scores[i]).c_str(), x, y+18 * i, s, s);
	}
}