#ifndef _PLATFORM_HPP_
#define _PLATFORM_HPP_

#include "Entity.hpp"



class Platform : public Entity {
public:
	Platform(Point, string, int, int);
	virtual int get_broken_state();
	void set_point(Point);
	virtual void increase_broken_state();
};

class Static_Platform : public Platform {
public:
	Static_Platform(Point);
	void move();
private:

};

class Moving_Platform : public Platform {
public:
	Moving_Platform(Point);
	void move();
private:
	int vx = MOVING_PLATFORM_VELOCITY;
};

class Breaking_Platform : public Platform {
public:
	Breaking_Platform(Point);
	void move();
	int get_broken_state();
	void increase_broken_state();
private:
	int broken_state = 0;

};

#endif