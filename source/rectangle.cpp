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

void Rect::draw( Window const& win) {
	float thickness = 1.0f;
	if (is_inside({ static_cast<float>(win.mouse_position().first), static_cast<float>(win.mouse_position().second) }) == true) {
		thickness = thickness * 2.0f;
	}
	win.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
	win.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
	win.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
	win.draw_line(max_.x, min_.y, min_.x, min_.y, color_.r, color_.g, color_.b, thickness);
}

void Rect::draw( Window const& win, float thickness) {
	if (is_inside({ static_cast<float>(win.mouse_position().first), static_cast<float>(win.mouse_position().second) }) == true) {
		thickness = thickness * 2.0f;
	}
	win.draw_line(min_.x, min_.y, min_.x, max_.y, color_.r, color_.g, color_.b, thickness);
	win.draw_line(min_.x, max_.y, max_.x, max_.y, color_.r, color_.g, color_.b, thickness);
	win.draw_line(max_.x, max_.y, max_.x, min_.y, color_.r, color_.g, color_.b, thickness);
	win.draw_line(max_.x, min_.y, min_.x, min_.y, color_.r, color_.g, color_.b, thickness);
}

bool Rect::is_inside(Vec2 const& m_pos) {
	if (m_pos.x >= min_.x && m_pos.x <= max_.x && m_pos.y >= min_.y && m_pos.y <= max_.y) {
		return true;
	}
	return false;
}