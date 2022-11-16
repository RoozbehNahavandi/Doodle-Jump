#include "Platform.hpp"

Platform::Platform(Point _p, string _type, int _width = PLATFORM_WIDTH*COEFF, int _height =PLATFORM_HEIGHT*COEFF)
 : Entity(_p, _type, _width, _height) {}

 int Platform::get_broken_state() { return 0; };

 void Platform::set_point(Point _p) {
 	point = _p;
 }

 void Platform::increase_broken_state() {}



Static_Platform::Static_Platform(Point _p) : Platform(_p, "Static_Platform") {}


void Static_Platform::move() {};

Moving_Platform::Moving_Platform(Point _p) : Platform(_p, "Moving_Platform") {}

void Moving_Platform::move() {
	point.x +=vx;
	if (point.x - PLATFORM_WIDTH/2 < 0)
		vx = -vx;
	if (point.x +PLATFORM_WIDTH/2 > WIDTH*COEFF)
		vx = -vx;
};

Breaking_Platform::Breaking_Platform(Point _p) : Platform(_p, "Breaking_Platform") {}

void Breaking_Platform::move() {};

int Breaking_Platform::get_broken_state() { return broken_state; };

void Breaking_Platform::increase_broken_state() { broken_state++; };