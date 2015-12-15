#pragma once
#include "gameobject.h"
#include <math.h>

class Bullet : public gameObject
{
public:
	float lifespan;

	Bullet(float x, float y, float bSpeed) : gameObject(x, y, 5), lifespan(3.f)
	{
		speed = bSpeed;
		color = GREEN;
		vel.y = speed;
		sprite = spriteParticle;
	}
	
	void onUpdate() 
	{
		lifespan -= sfw::getDeltaTime();
		pos.x += sin(lifespan * 5);
		radius -= sfw::getDeltaTime() * 10;
		if (lifespan < 0) active = false;
	}
};