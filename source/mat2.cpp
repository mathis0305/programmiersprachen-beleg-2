#include <array>
#include "mat2.hpp"
Mat2& Mat2::operator *=(Mat2 const& rhs) {
	float temp_00 = e_00;
	float temp_10 = e_10;
	float temp_01 = e_01;
	float temp_11 = e_11;

	e_00 = temp_00 * rhs.e_00 + temp_10 * rhs.e_01;
	e_10 = temp_00 * rhs.e_10 + temp_10 * rhs.e_11;
	e_01 = temp_01 * rhs.e_00 + temp_11 * rhs.e_01;
	e_11 = temp_01 * rhs.e_10 + temp_11 * rhs.e_11;

	return *this;
}

Mat2 operator *(Mat2 const& m1, Mat2 const& m2) {
	Mat2 temp{ m1 };

	return temp *= m2;
}

Vec2 operator*(Mat2 const& m, Vec2 const& v) {
	Vec2 v_new;
	v_new.x = m.e_00 * v.x + m.e_10 * v.y;
	v_new.y = m.e_01 * v.x + m.e_11 * v.y;

	return v_new;
}

Mat2 make_rotation_mat2(float phi) {
	Mat2 rot_mat;
	rot_mat.e_00 = cos(phi);
	rot_mat.e_10 = -sin(phi);
	rot_mat.e_01 = sin(phi);
	rot_mat.e_11 = cos(phi);

	return rot_mat;
}

Mat2 m1;
Mat2 m2{ 0.5f, 1.0f, 1.5f, 2.0f };
Mat2 m3{ 2.5f, 3.0f, 3.5f, 4.0f };
Mat2 m4{ 4.5f, 5.0f, 5.5f, 6.0f };