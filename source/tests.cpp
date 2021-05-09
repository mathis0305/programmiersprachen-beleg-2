#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath> 
#include "vec2.hpp"
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"



Vec2 a;
Vec2 b{ 5.1f, -9.3f };
Vec2 c{ 5.0f, 10.0f };
Vec2 d{ -8.6f, 24.9f };

Mat2 m1;
Mat2 m2{ 0.5f, 1.0f, 1.5f, 2.0f };
Mat2 m3{ 2.5f, 3.0f, 3.5f, 4.0f };
Mat2 m4{ 4.5f, 5.0f, 5.5f, 6.0f };

Circle c1;
Circle c2{ {2.0f, -3.3f}, 5.2f, {0.0f, 1.0f, 0.0f} };

Rect r1;
Rect r2{ {-5.0f, -5.0f}, {5.0f, 5.0f}, {1.0f, 0.0f, 0.0f} };

// Test 1: struct vec2
TEST_CASE("test struct vec2", "[vec2]") {
	// definition tests
	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);
	REQUIRE(b.x == 5.1f);
	REQUIRE(b.y == -9.3f);
}

// Test 2: operators vec2
TEST_CASE("test equality operators for vec2", "[e-op]") {
	// addition tests
	REQUIRE((a += b).x == 5.1f);
	REQUIRE(a.y        == -9.3f);

	// subtraction tests
	REQUIRE((a -= b).x == 0.0f);
	REQUIRE(a.y == 0.0f);

	// multiplying tests
	REQUIRE((c *= 2).x == 10.0f);
	REQUIRE(c.y == 20.0f);

	// division tests
	REQUIRE((c /= 2).x == 5.0f);
	REQUIRE(c.y == 10.0f);
}

// Test 3: operators vec2
TEST_CASE("test operators for vec2", "[op]") {
	// addition tests
	REQUIRE(Approx((c + d).x) == -3.6f);
	REQUIRE((c + d).y == 34.9f);
	REQUIRE(c.x == 5.0f);

	// subtraction tests
	REQUIRE((c - d).x == 13.6f);
	REQUIRE((c - d).y == -14.9f);
	REQUIRE(c.y == 10.0f);

	// multiplying tests
	REQUIRE((c * 2).x == 10.0f);
	REQUIRE((c * 2).y == 20.0f);
	REQUIRE(c.x == 5.0f);
	REQUIRE((2 * c).x == 10.0f);
	REQUIRE((2 * c).y == 20.0f);
	REQUIRE(c.y == 10.0f);

	// division tests
	REQUIRE((c / 2).x == 2.5f);
	REQUIRE((c / 2).y == 5.0f);
	REQUIRE(c.y == 10.0f);
	REQUIRE(c.x == 5.0f);
}

// Test 4: struct mat2
TEST_CASE("test matrix initialisation for mat2", "[matrix_init]") {
	REQUIRE(m1.e_00 == 1.0f);
	REQUIRE(m1.e_10 == 0.0f);
	REQUIRE(m1.e_01 == 0.0f);
	REQUIRE(m1.e_11 == 1.0f);
}

// Test 5: matrix multiplication
TEST_CASE("test matrix multiplication for mat2", "[matrix_multi]") {
	REQUIRE((m2 *= m3).e_00 == Approx((19.0f / 4.0f)));
	REQUIRE(m2.e_10 == Approx((11.0f / 2.0f)));
	REQUIRE(m2.e_01 == Approx((43.0f / 4.0f)));
	REQUIRE(m2.e_11 == Approx((25.0f / 2.0f)));

	REQUIRE((m3 * m4).e_00 == Approx((111.0f / 4.0f)));
	REQUIRE((m3 * m4).e_10 == Approx((61.0f / 2.0f)));
	REQUIRE((m3 * m4).e_01 == Approx((151.0f / 4.0f)));
	REQUIRE((m3 * m4).e_11 == Approx((83.0f / 2.0f)));
}

// Test 6: matrix-vector multiplication
TEST_CASE("test matrix-vector multiplication", "[mat_vec_multi]") {
	REQUIRE((m4 * c).x == Approx(72.5f));
	REQUIRE((m4 * c).y == Approx(87.5f));
	REQUIRE(m4.e_00 == Approx(4.5f));
	REQUIRE(c.x == Approx(5.0f));
}

// Test 7: rotation matrix
TEST_CASE("test rotation matrix", "[rot_mat]") {
	REQUIRE(make_rotation_mat2(3.14159265359f).e_00 == Approx(-1.0f));
	REQUIRE(make_rotation_mat2(3.14159265359f).e_10 == Approx(0.0f));
	REQUIRE(make_rotation_mat2(3.14159265359f).e_01 == Approx(0.0f));
	REQUIRE(make_rotation_mat2(3.14159265359f).e_11 == Approx(-1.0f));
}

// Test 8: circumference for circle and rectangle
TEST_CASE("test circumference", "[circumference]") {
	REQUIRE(c1.circumference() == Approx(4.0f * acos(0.0)));
	REQUIRE(c2.circumference() == Approx(4.0f * acos(0.0) * 5.2f));
	REQUIRE(r1.circumference() == Approx(4.0f));
	REQUIRE(r2.circumference() == Approx(40.0f));
}

// Test 9: is_inside method
TEST_CASE("test is_inside", "[inside]") {
	REQUIRE(c2.is_inside({ 1.0f, -4.0f }) == true);
	REQUIRE(c2.is_inside({ 10.0f, -3.0f }) == false);
	REQUIRE(r2.is_inside({ 1.0f, -2.0f }) == true);
	REQUIRE(r2.is_inside({ 10.0f, -4.0f }) == false);
}

int main(int argc, char *argv[]) {
    return Catch::Session().run(argc, argv);
}
