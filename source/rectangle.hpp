#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rect {
public:
	Vec2 min_ = { 0.0f, 0.0f };
	Vec2 max_ = { 1.0f, 1.0f };
	Color color_;

	float circumference() const;
	void draw(Window const& win);
	void draw(Window const& win, float thickness);
};

#endif // RECTANGLE_HPP