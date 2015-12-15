#pragma once
#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include "baseState.h"
#include "const.h"
#include "particle.h"
#include <vector>

class GameState : public BaseState
{
public:
	Player player;
	std::vector<Bullet> bullets;
	std::vector<Enemy> enemies;
	std::vector<Particle> particles;
	float spawnrate;
	float spawndelay;
	unsigned score;
	
	GameState() : player((BOUNDS_RIGHT + BOUNDS_LEFT) / 2, BOUNDS_BOTTOM),
		spawndelay(0), spawnrate(1.8f), score(0)
	{
		gameObject::gs = this;
		//spawnEnemies(player.pos.x, BOUNDS_TOP);
	}

	void reset()
	{
		score = 0;
		spawndelay = 0;
		spawnrate = 1.8f;
		player = Player((BOUNDS_RIGHT + BOUNDS_LEFT) / 2, BOUNDS_BOTTOM);
		bullets.clear();
		enemies.clear();
		particles.clear();
	}
	

	void update();
	void draw();
	void spawnBullet(float x, float y, float bSpeed);
	void spawnEnemies(float x, float y);
	void spawnParticle(float x, float y, float a_startRad, float a_endRad,
						float a_lifetime, unsigned a_color);
};