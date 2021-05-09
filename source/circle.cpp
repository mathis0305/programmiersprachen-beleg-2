#include "circle.hpp"


float Circle::circumference() const{

	// 4 * Pi * r gives the circumference
	return 4.0f * acos(0.0f) * radius_;
}


// draw without given thickness
void Circle::draw(int num, Window const& win) {

	// double thickness if mouse is inside the circle
	float thickness = 1.0f;
	if (is_inside({ static_cast<float>(win.mouse_position().first), static_cast<float>(win.mouse_position().second) }) == true) {
		thickness = thickness * 2.0f;
	}

	// actual draw function
	Vec2 circ_start1 = { radius_ / sqrt(2), radius_ / sqrt(2) };
	float angle = (4 * acos(0) / num);
	for (int i = 0; i < num; i++) {
		Mat2 rot_mat = make_rotation_mat2(angle);
		Vec2 circ_start2 = rot_mat * circ_start1;
		win.draw_line(circ_start1.x + center_.x, circ_start1.y + center_.y, circ_start2.x + center_.x, circ_start2.y + center_.y, color_.r, color_.g, color_.b, thickness);
		circ_start1 = circ_start2;
	}
}


// draw with given thickness
void Circle::draw(int num, Window const& win, float thickness) {

	// double thickness if mouse is inside the circle
	if (is_inside({ static_cast<float>(win.mouse_position().first), static_cast<float>(win.mouse_position().second) }) == true) {
		thickness = thickness * 2.0f;
	}

	// actual draw function
	Vec2 circ_start1 = { radius_ / sqrt(2), radius_ / sqrt(2)};
	float angle = (4 * acos(0) / num);
	for (int i = 0; i < num; i++) {
		Mat2 rot_mat = make_rotation_mat2(angle);
		Vec2 circ_start2 = rot_mat * circ_start1;
		win.draw_line(circ_start1.x + center_.x, circ_start1.y + center_.y, circ_start2.x + center_.x, circ_start2.y + center_.y, color_.r, color_.g, color_.b, thickness);
		circ_start1 = circ_start2;
	}
}

bool Circle::is_inside(Vec2 m_pos) {

	// return true if mouse is inside circle
	float distance = sqrt(((m_pos.x - center_.x) * (m_pos.x - center_.x)) + ((m_pos.y - center_.y) * (m_pos.y - center_.y)));
	if (distance <= radius_) {
		return true;
	}
	return false;
	
}