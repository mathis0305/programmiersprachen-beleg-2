#ifndef RECTANGLE.HPP
#define RECTANGLE_HPP
#include "vec2.hpp"

class rectangle {
public:
	Vec2 min_ = { 0.0f, 0.0f };
	Vec2 max_ = { 1.0f, 1.0f };

	float circumference() const;
};

#endif // RECTANGLE_HPP