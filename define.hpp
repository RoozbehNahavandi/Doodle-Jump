#include <string>
#include "src/rsdl.hpp"

#ifndef _DEFINE_
#define _DEFINE_

const int WIDTH = 640;
const int HEIGHT = 1024;
const double COEFF = 0.68;
const int ENEMY_WIDTH = 136;
const int ENEMY_HEIGHT = 184;
const int PLATFORM_WIDTH = 120;
const int PLATFORM_HEIGHT = 36;
const int DOODLE_WIDTH = 124;
const int DOODLE_HEIGHT = 120;
const int SPRING_WIDTH = 56;
const int SPRING_HEIGHT= 46;
const int DELAY_TIME = 10;
const int JUMPING_FRAME_LIMIT = 30;
const int DOODLE_HORIZONTAL_VELOCITY = 4;
const int MOVING_PLATFORM_VELOCITY = 1;
const int FALLING = 1;
const int ENEMY_TOUCH = 2;
const int ALIVE = 0;
const double DEFAULT_ACCELERATION = -0.1;
const double INITIAL_VERTICAL_VELOCITY = 6;
const char TRY_AGAIN = 'r';
const char QUIT = 'q';
const char GO_LEFT = 'a';
const char GO_RIGHT = 'd';
const std::string FALLING_SOUND = "sound/falling-sound-arcade.wav";
const std::string SPRING_JUMP_SOUND = "sound/jump-spring.wav";
const std::string MONSTER_CRASH_SOUND = "sound/monster-crash.wav";
const std::string JUMP_ON_PLATFORM_SOUND = "sound/jump.wav";
const std::string BREAKING_PLATFORM_SOUND = "sound/breaking-arcade.wav";
const std::string MAP_NAME = "map.txt";
const std::string font_adr = "FreeSans-LrmZ.ttf";

const Rectangle STATIC_PLATFORM_LOCATION = Rectangle(2, 0, PLATFORM_WIDTH, PLATFORM_HEIGHT);
const Rectangle MOVING_PLATFORM_LOCATION = Rectangle(2, 34, PLATFORM_WIDTH, PLATFORM_HEIGHT);
const Rectangle BREAKING_PLATFORM_LOCATION = Rectangle(2, 140, PLATFORM_WIDTH, PLATFORM_HEIGHT);
const Rectangle CLOSE_SPRING_LOCATION = Rectangle(800, 177, SPRING_WIDTH, SPRING_HEIGHT);
const Rectangle OPEN_SPRING_LOCATION = Rectangle(800, 187, SPRING_WIDTH, SPRING_HEIGHT);
const Rectangle ENEMY_LOCATION = Rectangle(130, 0, ENEMY_WIDTH, ENEMY_HEIGHT);
const Rectangle LEVEL1_BREAKING_PLATFORM_LOCATION = Rectangle(2, 190, PLATFORM_WIDTH, PLATFORM_HEIGHT+10);
const Rectangle LEVEL2_BREAKING_PLATFORM_LOCATION = Rectangle(2, 240, PLATFORM_WIDTH, PLATFORM_HEIGHT+30);
const Rectangle LEVEL3_BREAKING_PLATFORM_LOCATION = Rectangle(2, 280, PLATFORM_WIDTH, PLATFORM_HEIGHT+50);


const std::string PICTURES_FILE = "assets/main pictures/game-tiles.png";
const std::string RIGHT_DOODLE_PICTURE = "assets/main pictures/right.png";
const std::string LEFT_DOODLE_PICTURE = "assets/main pictures/left.png";
const std::string RIGHT_JUMPING_DOODLE_PICTURE = "assets/main pictures/right_jumping.png";
const std::string LEFT_JUMPING_DOODLE_PICTURE = "assets/main pictures/left_jumping.png";

const Rectangle DOODLE_RECTANGLE = Rectangle(125, 0, DOODLE_WIDTH, DOODLE_HEIGHT);


enum Direction {Right, Left};
enum Spring_Status {Open, Close};

#endif
