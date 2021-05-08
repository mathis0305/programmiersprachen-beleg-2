#ifndef RECTANGLE.HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class rectangle {
public:
	Vec2 min_ = { 0.0f, 0.0f };
	Vec2 max_ = { 1.0f, 1.0f };
	color color;

	float circumference() const;
};

#endif // RECTANGLE_HPP