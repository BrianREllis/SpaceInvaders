#include "sfwdraw.h"
#include "gameobject.h"
#include "player.h"
#include "const.h"
#include "gamestate.h"

void Player::onUpdate()
{
	vel = { 0,0 };
	delay += sfw::getDeltaTime();

	if (sfw::getKey(' ') && delay > rof)
	{
		delay = 0;
		gs->spawnBullet(pos.x, pos.y, 200);
	}

	/*if (sfw::getKey('W'))
	{
		vel.y = -speed;
	}*/
	if (sfw::getKey('D'))
	{
		vel.x = speed;
	}
	if (sfw::getKey('A'))
	{
		vel.x = -speed;
	}
}

void Player::onCollision(gameObject &o)
{
	if (o.vel.y < 0)
	{
		health--;
		o.setInactive();
		switch (health)
		{
		case 1: color = GREEN; break;
		case 0: color = YELLOW; break;
		case -1: setInactive(); break;
		}
	}
}