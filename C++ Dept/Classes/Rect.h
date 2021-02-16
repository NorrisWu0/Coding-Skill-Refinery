#pragma once
#include <string>

struct vec2
{
	int x;
	int y;
};

class Rect
{
	vec2 ll, tr;
	int width, height;

	public:
	Rect(vec2 _ll, vec2 _tr);
};

