#include "Rect.h"

Rect::Rect(vec2 _ll, vec2 _tr)
{
	ll = _ll;
	tr = _tr;

	width = tr.x - ll.x;
	height = tr.y - tr.y;
}
