#pragma once
#include "vec2.h"
#include "sfwdraw.h"
#include "const.h"

class gameObject 
{
	public:

		static GameState *gs;

		vec2 pos;
		vec2 vel;
		float radius;
		unsigned color;
		float speed;
		bool active = true;
		unsigned sprite;

		float moveSpeed = 80;

		gameObject(float x, float y, float radius) : pos({x, y}), speed(0), color(GREEN), vel({0,0}), radius(radius), active(true)
		{}

		void draw();
		void update();

		void setInactive()
		{
			if (!active) return;
			active = false;
			onInactive();
		}

		virtual void onUpdate() {}
		virtual void onDraw() {}
		virtual void onCollision(gameObject &o) {}
		virtual void onInactive() {}
};

void collides(gameObject &a, gameObject &b);