#include "Vec2.hpp"

Vec2& Vec2::operator+=(Vec2 const& rhs) {
	x += rhs.x;
	y += rhs.y;

	return *this;
}

Vec2& Vec2::operator-=(Vec2 const& rhs) {
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

Vec2& Vec2::operator*=(float rhs) {
	x *= rhs;
	y *= rhs;

	return *this;
}

Vec2& Vec2::operator/=(float rhs) {
	x /= rhs;
	y /= rhs;

	return *this;
}


Vec2 a;
Vec2 b{ 5.1f, -9.3f };
Vec2 c{ 5.0f, 10.0f };
