#include "rectangle.hpp"

float rectangle::circumference() const {
	float dif_x = max_.x - min_.x;
	float dif_y = max_.y - min_.y;

	if (dif_x < 0.0f) {
		dif_x = dif_x * (-1.0f);
	}

	if (dif_y < 0.0f) {
		dif_y = dif_y * (-1.0f);
	}
	return 2.0f*dif_x + 2.0f*dif_y;
}

rectangle r1;
rectangle r2{ {-5.0f, -5.0f}, {5.0f, 5.0f}, {1.0f, 0.0f, 0.0f} };