#include <cmath>
#include "vec2.h"

void passByVal(int d)
{
	d = 4;
}

void passByRef(int &d)
{
	d = 4;
}

void passByPtr(int *p)
{
	*p = 4;
}

float distance(vec2 pos1, vec2 pos2)
{
	float a = (pos2.x - pos1.x) * (pos2.x - pos1.x);
	float b = (pos2.y - pos1.y) * (pos2.y - pos1.y);
	float c = a + b;
	float d = sqrt(c);
	return d;
}

bool circleCollision(vec2 pos1, float rad1, vec2 pos2, float rad2)
{
	float d = distance(pos1, pos2);
	float r = rad1 + rad2;
	return d < r;
}

vec2 euler(vec2 pos, vec2 vel, float duration)
{
	return pos + vel * duration;
}

vec2 operator+(vec2 a, vec2 b)
{
	vec2 retval;
	retval.x = a.x + b.x;
	retval.y = a.y + b.y;
	return retval;
}

vec2 operator-(vec2 a, vec2 b)
{
	vec2 retval;
	retval.x = a.x - b.x;
	retval.y = a.y - b.y;
	return retval;
}

vec2 operator*(vec2 a, float b)
{
	vec2 retval;
	retval.x = a.x * b;
	retval.y = a.y * b;
	return retval;
}

vec2 operator/(vec2 a, float b)
{
	vec2 retval;
	retval.x = a.x / b;
	retval.y = a.y / b;
	return retval;
}

bool operator==(vec2 a, vec2 b)
{
	return a.x == b.x && a.y == b.y;
}

float randRange(float min, float max)
{
	float alpha = rand() / (RAND_MAX * 1.f);

	return min + alpha *(max - min);
}

float lerp(float start, float end, float alpha)
{
	return start + alpha * (end - start);
}