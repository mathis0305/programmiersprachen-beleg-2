#include "circle.hpp"
#include "vec2.hpp"


float circle::circumference() const{
	return 4.0 * acos(0.0) * radius_;
}

circle c1;
circle c2{ {2.0, -3.3}, 5.2 };	