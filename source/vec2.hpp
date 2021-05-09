#ifndef  VEC2_HPP
#define VEC2_HPP

#include <iostream>

/*EXPLANATION include guards are commands to avoid double includes.
  Before actually including this file they check if some of the files
  parts were already included via previous including commands.
  If you don't do this it is possible to include the struct Vec2 two
  times and this is a double declaration. It would lead to a compile
  error. */

// Vec2 data type definition
struct Vec2 {
	float x = 0.0f;
	float y = 0.0f;

	// operator
	Vec2& operator+=(Vec2 const& rhs);
	Vec2& operator-=(Vec2 const& rhs);
	Vec2& operator*=(float rhs);
	Vec2& operator/=(float rhs);

};

// Vec2 operator
Vec2 operator +(Vec2 const& u, Vec2 const& v);
Vec2 operator -(Vec2 const& u, Vec2 const& v);
Vec2 operator *(Vec2 const& v, float s);
Vec2 operator *(float s, Vec2 const& v);
Vec2 operator /(Vec2 const& v, float s);

#endif // VEC2_HPP
