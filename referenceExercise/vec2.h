#pragma once
void passByVal(int d);
void passByRef(int &d);
void passByPtr(int *p);

void passByConstRef(const int &d);
void passByConstPtr(const int *p);

struct vec2 {
	float x, y;
};

struct circle {
	vec2 pos;
	float radius;
};

float distance(vec2 pos1, vec2 pos2);

bool circleCollision(vec2 pos1, float rad1, 
					 vec2 pos2, float rad2);

vec2 euler(vec2 pos, vec2 vel, float duration);

vec2 operator+(vec2 a, vec2 b);
vec2 operator-(vec2 a, vec2 b);
vec2 operator*(vec2 a, float b);
vec2 operator/(vec2 a, float b);
bool operator==(vec2 a, vec2 y);

float randRange(float min, float max);

float lerp(float start, float end, float alpha);