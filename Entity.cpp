#include "Entity.hpp"


using namespace std;



Entity::Entity(Point _p, string _type, int _width, int _height) 
	: height(_height), width(_width), point(_p), entity_type(_type) {}


Point Entity::get_point() { return point; };


string Entity::get_type() { return entity_type; };

int Entity::get_width() { return width; };
int Entity::get_height() { return height; };
int Entity::get_y() { return point.y; };
int Entity::get_x() { return point.x; };
void Entity::set_y(int new_height) { point.y = new_height; };
