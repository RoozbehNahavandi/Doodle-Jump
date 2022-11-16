
#include "Enemy_Spring.hpp"
#include <string> 

using namespace std;

Enemy::Enemy(Point _p, string type, int width, int height) : Entity(_p, type, width, height) {}

void Enemy::move() {}

Spring::Spring(Point _p, string type, int width, int height) : Entity(_p, type, width, height) {};

void Spring::move() {}

bool Spring::is_open() { return status == Open; };
void Spring::open_spring() { status = Open; };