#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"

class circle {
public:
	Vec2 center_ = { 1.0f, 1.0f };
	float radius_ = 1.0f;
	Color color;

	float circumference() const;
};

#endif // CIRCLE_HPP