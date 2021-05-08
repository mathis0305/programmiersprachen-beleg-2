#include "circle.hpp"


float circle::circumference() const{
	return 4.0f * acos(0.0f) * radius_;
}

circle c1;
circle c2{ {2.0f, -3.3f}, 5.2f, {0.0f, 1.0f, 0.0f} };