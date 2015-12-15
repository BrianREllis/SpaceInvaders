#include "gamestate.h"
#include <fstream>

void GameState::update()
{
	spawndelay += sfw::getDeltaTime();

	if (spawndelay > spawnrate)
	{
		spawndelay = 0;

		spawnEnemies(randRange(BOUNDS_LEFT, BOUNDS_RIGHT), BOUNDS_TOP);
	}


	player.update();
	for (int i = 0; i < bullets.size(); ++i)
		bullets[i].update();
	for (int i = 0; i < enemies.size(); ++i)
		enemies[i].update();

	for (int i = 0; i < particles.size(); ++i)
		particles[i].update();

	for (int i = 0; i < bullets.size(); ++i)
		collides(player, bullets[i]);

	for (int i = 0; i < enemies.size(); ++i)
		for (int j = 0; j < bullets.size(); ++j)
			collides(enemies[i], bullets[j]);

	for (int i = 0; i+1 < bullets.size(); ++i)
		for (int j = i+1 ; j < bullets.size(); ++j)
			collides(bullets[i], bullets[j]);

	if (applicationState == GAME)
	{
		if (!player.active)
		{
			std::fstream fout("scores.dat", std::ios_base::out | std::ios_base::app);
			fout << score << std::endl;
			fout.close();

			applicationState = VICTORY;
		}
		if (sfw::getKey('P'))
			applicationState = PAUSE;
	}
	else
	{
		player.setInactive();
		spawnrate = 1.8f;
	}
}

void GameState::draw()
{
	player.draw();
	for (int i = 0; i < bullets.size(); ++i)
		bullets[i].draw();
	for (int i = 0; i < enemies.size(); ++i)
		enemies[i].draw();
	for (int i = 0; i < particles.size(); ++i)
		particles[i].draw();
}

void GameState::spawnBullet(float x, float y, float bSpeed)
{
	Bullet b(x, y, bSpeed);

	for (int i = 0; i < bullets.size(); ++i)
	{
		if (bullets[i].lifespan < 0)
		{
			bullets[i] = b;
			return;
		}
	}

	bullets.push_back(b);
}

void GameState::spawnEnemies(float x, float y)
{
	Enemy b(x, y);

	for (int i = 0; i < enemies.size(); ++i)
		if (!enemies[i].active)
		{
			enemies[i] = b;
			return;
		}
	enemies.push_back(b);
}

void GameState::spawnParticle(float x, float y, float a_startRad, float a_endRad,
	float a_lifetime, unsigned a_color)
{
	Particle b(x, y, a_startRad, a_endRad, a_lifetime, a_color);
	for (int i = 0; i < particles.size(); ++i)
		if (!particles[i].active)
		{
			particles[i] = b;
			return;
		}
	particles.push_back(b);
}