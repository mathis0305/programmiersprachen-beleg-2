#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.cpp"
#include "mat2.cpp"

TEST_CASE("test struct vec2", "[vec2]") {
	// definition tests
	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);
	REQUIRE(b.x == 5.1f);
	REQUIRE(b.y == -9.3f);
}

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

TEST_CASE("test matrix initialisation for mat2", "[matrix_init]") {
	REQUIRE(m1.e_00 == 1.0f);
	REQUIRE(m1.e_10 == 0.0f);
	REQUIRE(m1.e_01 == 0.0f);
	REQUIRE(m1.e_11 == 1.0f);
}


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

TEST_CASE("test matrix-vector multiplication", "[mat_vec_multi]") {
	REQUIRE((m4 * c).x == Approx(72.5f));
	REQUIRE((m4 * c).y == Approx(87.5f));
	REQUIRE(m4.e_00 == Approx(4.5f));
	REQUIRE(c.x == Approx(5.0f));
}

int main(int argc, char *argv[]) {
    return Catch::Session().run(argc, argv);
}
