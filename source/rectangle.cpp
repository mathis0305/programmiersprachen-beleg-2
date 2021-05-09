#include "rectangle.hpp"

float Rect::circumference() const {
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

void Rect::draw(Window const& win) {
	win.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, 2.0f);
	win.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b, 2.0f);
	win.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b, 2.0f);
	win.draw_line(max_.x, min_.y, min_.x, min_.y, color_.r, color_.g, color_.b, 2.0f);
}