#include "Entity.hpp"
#include "define.hpp"
#include <vector>
#include "Platform.hpp"
#include "Enemy_Spring.hpp"

#ifndef _DOODLE_HPP_
#define _DOODLE_HPP_

class Doodle : public Entity {
public:
	Doodle(double vx = 0, double vy = INITIAL_VERTICAL_VELOCITY);
	void initialize_doodle();
	void move();
	double get_vy();
	double get_vx();
	Direction get_direction();
	void move_vertically(vector<Platform*>, vector<Spring*>);
	bool is_on_platform(vector<Platform*>);
	bool is_on_spring(vector<Spring*>);
	int get_jumping_frame();
	void increase_jumping_frame();
	void set_jumping_frame_zero();
	bool has_touched_enemy(vector<Enemy*>);
	void set_vx(double);
	void fall(int);
	bool is_on_breaking_platform(vector<Platform*>);
private:
	void move_horizontally();
	int jumping_frame = 0;
	double vy;
	double vx;
	const double acceleration = DEFAULT_ACCELERATION;
	Direction direction;
};

#endif