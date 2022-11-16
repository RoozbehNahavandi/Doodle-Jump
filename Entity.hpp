
#include "src/rsdl.hpp"
#include <iostream>
#include <cmath>
#include "define.hpp"
#include <string>

using namespace std;

#ifndef _ENTITY_
#define _ENTITY_

class Entity {
public:
	Entity(Point, string, int, int);
	
	string get_type();
	Point get_point();
	int get_width();
	int get_height();
	int get_y();
	int get_x();
	void set_y(int);
	virtual void move() = 0;

protected:
	string entity_type;
	Point point;
	int height;
	int width;
};

#endif
