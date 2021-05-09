#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <cmath>
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle {
public:
	Vec2 center_ = { 1.0f, 1.0f };
	float radius_ = 1.0f;
	Color color_;

	float circumference() const;
	void draw(int num, Window const& win);
	void draw(int num, Window const& win, float thickness);
	bool is_inside(Vec2 m_pos);
};

#endif // CIRCLE_HPP