#include "rectangle.hpp"
#include "vec2.hpp"

float rectangle::circumference() const {
	float dif_x = max_.x - min_.x;
	float dif_y = max_.y - min_.y;

	if (dif_x < 0) {
		dif_x = dif_x * (-1);
	}

	if (dif_y < 0) {
		dif_y = dif_y * (-1);
	}
	return 2*dif_x + 2*dif_y;
}

rectangle r1;
rectangle r2{ {-5.0, -5.0}, {5.0, 5.0}, {1.0, 0.0, 0.0} };