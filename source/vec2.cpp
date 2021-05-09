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


Vec2 operator +(Vec2 const& u, Vec2 const& v) {
	Vec2 temp{ u };

	return temp += v;
}

Vec2 operator -(Vec2 const& u, Vec2 const& v) {
	Vec2 temp{ u };

	return temp -= v;
}

Vec2 operator *(Vec2 const& v, float s) {
	Vec2 temp{ v };

	return temp *= s;
}

Vec2 operator *(float s, Vec2 const& v) {
	Vec2 temp{ v };

	return temp *= s;
}

Vec2 operator /(Vec2 const& v, float s) {
	Vec2 temp{ v };

	return temp /= s;
}



