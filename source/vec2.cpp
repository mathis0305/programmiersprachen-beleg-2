#include "Vec2.hpp"


// addition
Vec2& Vec2::operator+=(Vec2 const& rhs) {
	x += rhs.x;
	y += rhs.y;

	return *this;
}

// subtraction
Vec2& Vec2::operator-=(Vec2 const& rhs) {
	x -= rhs.x;
	y -= rhs.y;

	return *this;
}

// multiplication
Vec2& Vec2::operator*=(float rhs) {
	x *= rhs;
	y *= rhs;

	return *this;
}

// division
Vec2& Vec2::operator/=(float rhs) {
	x /= rhs;
	y /= rhs;

	return *this;
}

// addition
Vec2 operator +(Vec2 const& u, Vec2 const& v) {
	Vec2 temp{ u };

	return temp += v;
}

// subtraction
Vec2 operator -(Vec2 const& u, Vec2 const& v) {
	Vec2 temp{ u };

	return temp -= v;
}

// multiplication Vec2 with float
Vec2 operator *(Vec2 const& v, float s) {
	Vec2 temp{ v };

	return temp *= s;
}

// multiplication float with Vec2
Vec2 operator *(float s, Vec2 const& v) {
	Vec2 temp{ v };

	return temp *= s;
}

// division
Vec2 operator /(Vec2 const& v, float s) {
	Vec2 temp{ v };

	return temp /= s;
}



