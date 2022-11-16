#include "Screen.hpp"
#include "define.hpp"
#include "Entity.hpp"
#include <sstream>
#include <string>
using namespace std;

Screen::Screen() 
	: window(WIDTH*COEFF, HEIGHT*COEFF, "Doodle Jump") {}

Window* Screen::get_window() { return &window; };

void Screen::draw_doodle(Doodle& doodle) {
	Rectangle rec = Rectangle(doodle.get_point().x - doodle.get_width()/2,
									  HEIGHT*COEFF - doodle.get_point().y - doodle.get_height(),
									   doodle.get_width(), doodle.get_height());
	if (doodle.get_direction() == Right)
		if (doodle.get_jumping_frame() < JUMPING_FRAME_LIMIT) {
			doodle.increase_jumping_frame();
			window.draw_img(RIGHT_JUMPING_DOODLE_PICTURE, rec);
		}
		else
			window.draw_img(RIGHT_DOODLE_PICTURE, rec);
	else 
		if (doodle.get_jumping_frame() < JUMPING_FRAME_LIMIT) {
			doodle.increase_jumping_frame();
			window.draw_img(LEFT_JUMPING_DOODLE_PICTURE, rec);
		}
		else
			window.draw_img(LEFT_DOODLE_PICTURE, rec);

}

void Screen::draw_entities(vector<Platform*> platforms, vector<Spring*> springs, vector<Enemy*> enemies, Doodle& doodle) {
	for (auto x : platforms)
		draw_platform(x);
	for (auto x : springs)
		draw_spring(x);
	for (auto x : enemies)
		draw_enemy(x);
	draw_doodle(doodle);
}
void Screen::draw_platform(Platform* platform) {
	Rectangle rec = Rectangle(platform->get_point().x - platform->get_width()/2,
									  HEIGHT*COEFF - platform->get_point().y - platform->get_height(),
									  platform->get_width(), platform->get_height());
	if (platform->get_type() == "Static_Platform")
		window.draw_img(PICTURES_FILE, rec, STATIC_PLATFORM_LOCATION);

	else if (platform->get_type() == "Moving_Platform")
		window.draw_img(PICTURES_FILE, rec, MOVING_PLATFORM_LOCATION);

	else if (platform->get_type() == "Breaking_Platform") {


		if (!platform->get_broken_state()) 
			window.draw_img(PICTURES_FILE, rec, BREAKING_PLATFORM_LOCATION);
		else break_animation(platform);

	
}
}

void Screen::break_animation(Platform* platform) {
	if (platform->get_broken_state() < 7) {
			platform->set_point(Point(platform->get_point().x, platform->get_point().y - 5));
			Rectangle rec = Rectangle(platform->get_point().x - platform->get_width()/2,
									  HEIGHT*COEFF - platform->get_point().y - platform->get_height(),
									  platform->get_width(), platform->get_height() + 10);
			window.draw_img(PICTURES_FILE, rec, LEVEL1_BREAKING_PLATFORM_LOCATION);
			platform->increase_broken_state();
		}
	else if (platform->get_broken_state() < 14) {
		platform->set_point(Point(platform->get_point().x, platform->get_point().y - 5));
		Rectangle rec = Rectangle(platform->get_point().x - platform->get_width()/2,
									  HEIGHT*COEFF - platform->get_point().y - platform->get_height(),
									  platform->get_width(), platform->get_height() + 30);
		window.draw_img(PICTURES_FILE, rec, LEVEL2_BREAKING_PLATFORM_LOCATION);
		platform->increase_broken_state();
	}
	else if (platform->get_broken_state() == 14) {
		platform->set_point(Point(platform->get_point().x, platform->get_point().y - 5));
		Rectangle rec = Rectangle(platform->get_point().x - platform->get_width()/2,
									  HEIGHT*COEFF - platform->get_point().y - platform->get_height(),
									  platform->get_width(), platform->get_height() + 50);
		if (platform->get_point().y + PLATFORM_HEIGHT*COEFF <= 0)
			platform->set_point(Point(platform->get_point().x, platform->get_point().y - 5));
			window.draw_img(PICTURES_FILE, rec, LEVEL3_BREAKING_PLATFORM_LOCATION);
	}


}


void Screen::draw_spring(Spring* spring) {
	if (spring->is_open()) {
		Rectangle rec = Rectangle(spring->get_point().x - spring->get_width()/2,
									  HEIGHT*COEFF - spring->get_point().y - spring->get_height(),
									   spring->get_width(), spring->get_height()*2.5);
		window.draw_img(PICTURES_FILE, rec, OPEN_SPRING_LOCATION);
	}
	else {
		Rectangle rec = Rectangle(spring->get_point().x - spring->get_width()/2,
									  HEIGHT*COEFF - spring->get_point().y - spring->get_height(),
									   spring->get_width(), spring->get_height());
		window.draw_img(PICTURES_FILE, rec, CLOSE_SPRING_LOCATION);
	}
}

void Screen::draw_enemy(Enemy* enemy) {
	Rectangle rec = Rectangle(enemy->get_point().x - enemy->get_width()/2,
									  HEIGHT*COEFF - enemy->get_point().y - enemy->get_height(),
									   enemy->get_width(), enemy->get_height());
	window.draw_img(PICTURES_FILE, rec, ENEMY_LOCATION);
}



void Screen::show_background() {
	string filename = "assets/main pictures/background.png";
	window.draw_img(filename);
}

void Screen::update() {
	window.update_screen();
}

string score_to_string(int score) {
	ostringstream os;
	os << "Score: " << score;
	return os.str();
}

void Screen::clear_screen() {
	window.clear();
}
void Screen::show_score(int score) {
	Point src = Point(WIDTH*COEFF - 100, 10);
	string score_str = score_to_string(score);
	window.show_text(score_str, src, BLACK, font_adr, 18);
}

void Screen::game_over_text(int score) {
	Point game_over_location = Point(WIDTH*COEFF/2 - 100, HEIGHT*COEFF/2 - 100);
	window.show_text("Game Over!", game_over_location, RED, font_adr, 40);
	string score_str = score_to_string(score);
	Point score_location = Point(WIDTH*COEFF/2 - 80, HEIGHT*COEFF/2);
	window.show_text(score_str, score_location, BLACK, font_adr, 35);
	string try_again = "Press 'r' to play again.";
	string quit = "Press 'q' to quit.";
	Point try_again_location = Point(WIDTH*COEFF/2 - 100, HEIGHT*COEFF/2 + 150);
	Point quit_location = Point(WIDTH*COEFF/2 - 75, HEIGHT*COEFF/2 + 200);
	window.show_text(try_again, try_again_location, BLACK, font_adr, 20);
	window.show_text(quit, quit_location, BLACK, font_adr, 20);
}

void Screen::play_sound(string filename) {
	window.play_sound_effect(filename);
}

