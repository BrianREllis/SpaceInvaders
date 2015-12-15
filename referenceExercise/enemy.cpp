#include "enemy.h"
#include "gamestate.h"
#include <math.h>

void Enemy::onUpdate()
{
	delay += sfw::getDeltaTime();
	if (delay > rof)
	{
		delay = 0;
		gs->spawnBullet(pos.x, pos.y, -300);
	}

	if (pos.y < BOUNDS_BOTTOM)
	{
		active = false;
	}
}


void  Enemy::onCollision(gameObject &o)
{
	if (o.vel.y > 0)
	{
		setInactive();
		o.setInactive();
		gs->score++;
	}
}

void Enemy::onInactive()
{
	gs->spawnParticle(pos.x, pos.y, 0, 100, .2f, YELLOW);
}