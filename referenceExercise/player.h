#pragma once
#include "gameobject.h"


class Player : public gameObject
{
public:
	float delay, rof;
	int health;

	Player(float x, float y) : gameObject(x, y, 15), delay(0), rof(.2f), health(2)
	{
		color = BLUE;
		speed = 120;
		sprite = spritePlayer;
	}

	void onUpdate();
	void onCollision(gameObject &o);
};