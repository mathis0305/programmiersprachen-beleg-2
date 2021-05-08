#ifndef CIRCLE.HPP
#define CIRCLE_HPP
#include "vec2.hpp"

class circle {
public:
	Vec2 center_ = { 1.0f, 1.0f };
	float radius_ = 1.0f;

	float circumference() const;
};

#endif // CIRCLE_HPP