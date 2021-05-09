#include "circle.hpp"


float Circle::circumference() const{
	return 4.0f * acos(0.0f) * radius_;
}


void Circle::draw(int num, Window const& win) {
	Vec2 circ_start1 = { radius_, radius_ };
	float angle = (4 * acos(0) / num);
	for (int i = 0; i < num; i++) {
		Mat2 rot_mat = make_rotation_mat2(angle);
		Vec2 circ_start2 = rot_mat * circ_start1;
		win.draw_line(circ_start1.x + center_.x, circ_start1.y + center_.y, circ_start2.x + center_.x, circ_start2.y + center_.y, color_.r, color_.g, color_.b);
		circ_start1 = circ_start2;
	}
	
}
