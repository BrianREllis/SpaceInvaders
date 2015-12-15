#pragma once
#include "gameobject.h"

class Particle : public gameObject
{
public:
	float startRad, endRad;
	float lifespan, lifetime;
	/*float endRad;
	float lifespan;
	unsigned endcolor;
	*/
	Particle(float x, float y, float a_startRad, float a_endRad, float a_lifetime, unsigned a_color)
		:gameObject(x, y, a_startRad), endRad(a_endRad), lifespan(0), lifetime(a_lifetime), startRad(a_startRad)
	{
		color = a_color;
		sprite = spriteParticle;
	}

	void onUpdate()
	{
		radius = lerp(startRad, endRad, lifespan / lifetime);

		lifespan += sfw::getDeltaTime();
		if (lifespan > lifetime) active = false;
	}
};