#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.cpp"

TEST_CASE("test_struct_vec2", "[vec2]") {
	// definition tests
	REQUIRE(a.x == 0.0f);
	REQUIRE(a.y == 0.0f);
	REQUIRE(b.x == 5.1f);
	REQUIRE(b.y == -9.3f);
}

TEST_CASE("test equality operators", "[e-op]") {
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


TEST_CASE("test operators", "[op]") {
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

int main(int argc, char *argv[]) {
    return Catch::Session().run(argc, argv);
}
