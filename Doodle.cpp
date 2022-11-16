#include "Doodle.hpp"
#include <vector>
Doodle::Doodle(double _vx, double _vy) : Entity(Point(WIDTH*COEFF/2,0), "Doodle", DOODLE_WIDTH*COEFF, DOODLE_HEIGHT*COEFF),
								   direction(Right)								
 {
	vx = _vx;
	vy = _vy;
}
void Doodle::move() {
	move_horizontally();
}

Direction Doodle::get_direction() { return direction; };
int Doodle::get_jumping_frame() { return jumping_frame; };
void Doodle::increase_jumping_frame() { jumping_frame +=1; };
void Doodle::set_jumping_frame_zero() { jumping_frame = 0; };
void Doodle::initialize_doodle() {
	vy = INITIAL_VERTICAL_VELOCITY;
	point = Point(WIDTH*COEFF/2, 0);
}


void Doodle::move_horizontally() {
	
	point.x +=vx;
	if (vx > 0)
		direction = Right;
	else if (vx < 0)
		direction = Left;

	if (point.x < 0)
		point.x = WIDTH*COEFF;
	else if (point.x > WIDTH*COEFF)
		point.x = 0;
}

double Doodle::get_vx() { return vx; };

void Doodle::fall(int vy) {
	point.y +=vy;
	point.x +=vx;
	if (point.x > WIDTH*COEFF)
		point.x = 0;
	if (point.x < 0)
		point.x = WIDTH*COEFF;
}

void Doodle::set_vx(double _vx) {
	vx = _vx;
}

bool Doodle::is_on_platform(vector<Platform*> platforms) {
	for (auto x : platforms) {
		string type = x->get_type();
			if (point.y < x->get_point().y - 2 + PLATFORM_HEIGHT*COEFF && point.y > x->get_point().y) {
				if ((point.x <= x->get_point().x + PLATFORM_WIDTH*COEFF/2 + DOODLE_WIDTH*COEFF/2 - 20 &&
					 x->get_point().x - PLATFORM_WIDTH*COEFF/2  - DOODLE_WIDTH*COEFF/2 + 20 <= point.x)) {
					if (type == "Static_Platform" ||type == "Moving_Platform")
					return true;
					else if (type == "Breaking_Platform") 
						if (x->get_broken_state() == 0) {
							x->increase_broken_state();
							return false;
					}
				
			}
		}
	}
	return false;
}

bool Doodle::is_on_breaking_platform(vector<Platform*> platforms) {
	for (auto x : platforms) {
			string type = x->get_type();
				if (point.y < x->get_point().y - 2 + PLATFORM_HEIGHT*COEFF && point.y > x->get_point().y) {
					if ((point.x <= x->get_point().x + PLATFORM_WIDTH*COEFF/2 + DOODLE_WIDTH*COEFF/2 - 20 &&
						 x->get_point().x - PLATFORM_WIDTH*COEFF/2  - DOODLE_WIDTH*COEFF/2 + 20 <= point.x)) {
						if (type == "Breaking_Platform")
							return true;
					}
				}
	}

	return false;
}

void Doodle::move_vertically(vector<Platform*> platforms, vector<Spring*> springs) {
	if (vy < 0) {
		if (is_on_platform(platforms)) {
			vy = INITIAL_VERTICAL_VELOCITY;
			set_jumping_frame_zero();
		}
		if (is_on_spring(springs)) {
			vy = 1.8*INITIAL_VERTICAL_VELOCITY;
			set_jumping_frame_zero();
		}
	}

	point.y +=vy;
	if (-INITIAL_VERTICAL_VELOCITY + 1 <= vy )
		vy +=acceleration;	
}

bool Doodle::has_touched_enemy(vector<Enemy*> enemies) {
	for (auto x : enemies) {
		int enemy_y = x->get_y();
		int enemy_x = x->get_x();
		if (point.y + DOODLE_HEIGHT*COEFF - 50 >= enemy_y  && point.y <= enemy_y + ENEMY_HEIGHT*COEFF + 50)
			if (point.x - DOODLE_WIDTH*COEFF/2 + 11 <= enemy_x + ENEMY_WIDTH*COEFF/2 && 
				point.x + DOODLE_WIDTH*COEFF/2 - 11 >= enemy_x - ENEMY_WIDTH*COEFF/2)
				return true;
	}
	return false;
}



double Doodle::get_vy() { return vy; };

bool Doodle::is_on_spring(vector<Spring*> springs) {
	for (auto x : springs) {
		if (point.y < x->get_point().y - 9 + SPRING_HEIGHT*COEFF && point.y > x->get_point().y) {
			if ((point.x <= x->get_point().x + SPRING_WIDTH*COEFF/2 + DOODLE_WIDTH*COEFF/2 - 30 &&
				x->get_point().x - SPRING_WIDTH*COEFF/2  - DOODLE_WIDTH*COEFF/2 + 30 <= point.x)) {
				x->open_spring();
				return true;
				}
			}
		
	}
	return false;
}