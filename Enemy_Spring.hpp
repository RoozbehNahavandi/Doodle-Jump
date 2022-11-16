#ifndef _ENEMY_HPP_
#define _ENEMY_HPP_


#include "Entity.hpp"
#include <string>
#include "define.hpp"
class Enemy : public Entity {
public:
	Enemy(Point, std::string type = "Enemy", int width = ENEMY_WIDTH*COEFF, int height = ENEMY_HEIGHT*COEFF);
	void move();
};

class Spring : public Entity {
public: 
	Spring(Point, std::string type = "Spring", int width = SPRING_WIDTH*COEFF, int height = SPRING_HEIGHT*COEFF);
	void move();
	bool is_open();
	void open_spring();
private:
	Spring_Status status = Close;
};


#endif