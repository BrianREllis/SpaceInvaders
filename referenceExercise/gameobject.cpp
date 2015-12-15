#include "gameobject.h"
#include "sfwdraw.h"


GameState *gameObject::gs;

void gameObject::update()
{
	if (!active) return;
	pos = euler(pos, vel, sfw::getDeltaTime());
	onUpdate();
}

void gameObject::draw()
{
	if (!active) return;
	sfw::drawCircle(pos.x, pos.y, radius, 12, color);
	sfw::drawTexture(sprite, pos.x, pos.y, radius * 2, radius * 2, 0, true, 0, color);
	onDraw();
}

void collides(gameObject &a, gameObject &b)
{
	if(a.active && b.active)
		if (circleCollision(a.pos, a.radius, b.pos, b.radius))
		{
			a.onCollision(b);
			b.onCollision(a);
		}
}