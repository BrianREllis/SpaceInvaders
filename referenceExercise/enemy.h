#pragma once
#include "gameobject.h"

class Enemy : public gameObject
{
public:
	float delay, rof;
	Enemy(float x, float y) : gameObject(x,y, 34), delay(0), rof(1.2f)
	{
		color = RED;
		speed = 50;
		vel.y = -speed;
		sprite = spriteEnemy;
	}	

	void onUpdate();
	void onInactive();
	void onCollision(gameObject &o);
};