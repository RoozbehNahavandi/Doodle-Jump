#include "game.hpp"


using namespace std;

void Game::play_game() {
	while (true) {
		initialize_game();
		get_entities_from_file();
		int lose_way = 0;

		while (true) {
			show_screen();
			update();
			delay(DELAY_TIME);
			lose_way = lost(enemies);
			if (lose_way)
				break;
		}
		lose_animation(lose_way);
		
		while(true) {
			Event e = screen.get_window()->poll_for_event();
			Event::EventType etype = e.get_type();
			if (etype == Event::EventType::QUIT) 
				exit(0);
			else if (etype == Event::EventType::KEY_PRESS) {
				char pressed_key = e.get_pressed_key();
				if (pressed_key == TRY_AGAIN) {
					break;
				}
				else if (pressed_key == QUIT)
					exit(0);
			}
		}
	}
}

void Game::initialize_game() {
	doodle.initialize_doodle();
	entities = {};
	platforms = {};
	springs = {};
	enemies = {};
	score = 0;
}

void Game::lose_animation(int lose_way) {
	screen.update();
	if (lose_way == FALLING) {
		screen.play_sound(FALLING_SOUND);
		screen.clear_screen();
		doodle.set_y(HEIGHT*COEFF);
		while (doodle.get_y() + DOODLE_HEIGHT > 0) {
			screen.show_background();
				doodle.fall(-INITIAL_VERTICAL_VELOCITY);
			screen.draw_doodle(doodle);
			screen.update();
			delay(DELAY_TIME);
		}
	}

	if (lose_way == ENEMY_TOUCH) {
		screen.play_sound(MONSTER_CRASH_SOUND);
		int time = 0;
		screen.clear_screen();
		while (doodle.get_y() + DOODLE_HEIGHT > 0 && time < 2) {
			screen.show_background();
			if (time == 0)
				screen.draw_entities(platforms, springs, enemies, doodle);
				doodle.fall(-INITIAL_VERTICAL_VELOCITY);
			screen.draw_doodle(doodle);
			screen.update();
			if (doodle.get_y() + DOODLE_HEIGHT < 0) {
				doodle.set_y(HEIGHT*COEFF);
				time++;
				screen.play_sound(FALLING_SOUND);

			}
			delay(DELAY_TIME);
		}
	}
	screen.game_over_text(score);
	screen.update();
}


int Game::lost(vector<Enemy*> enemies) {
	if (doodle.get_point().y + DOODLE_HEIGHT*COEFF <= 0)
		return FALLING;
	else if (doodle.has_touched_enemy(enemies))
		return ENEMY_TOUCH;
	return ALIVE;
}


void Game::update() {
	for (auto i : entities)
		i->move();
	doodle.move();
	doodle.move_vertically(platforms, springs);
	if (doodle.get_vy() < 0) {
		if (doodle.is_on_spring(springs))
			screen.play_sound(SPRING_JUMP_SOUND);
		else if (doodle.is_on_platform(platforms)) 
			screen.play_sound(JUMP_ON_PLATFORM_SOUND);
		else if (doodle.is_on_breaking_platform(platforms))
			screen.play_sound(BREAKING_PLATFORM_SOUND);
	}

	int diff = keep_doodle_in_screen();
	update_score(diff);
	while (screen.get_window()->has_pending_event()) {
		Event e = screen.get_window()->poll_for_event();
		Event::EventType etype = e.get_type();
		if (etype == Event::EventType::QUIT) 
			exit(0);
		else if (etype == Event::EventType::KEY_PRESS) {
			char pressed_key = e.get_pressed_key();
			if (pressed_key == GO_RIGHT)
			doodle.set_vx(DOODLE_HORIZONTAL_VELOCITY);
			else if (pressed_key == GO_LEFT)
				doodle.set_vx(-DOODLE_HORIZONTAL_VELOCITY); 
		}
		else if (etype == Event::EventType::KEY_RELEASE) {
			doodle.set_vx(0);
		}
	}
}

int Game::keep_doodle_in_screen() {
	if (doodle.get_y() > HEIGHT*COEFF/2) {
		int diff = doodle.get_y() - HEIGHT*COEFF/2;
		for (auto x : entities)
			x->set_y(x->get_y() - diff);
		doodle.set_y(doodle.get_y() - diff);
		return diff;
	}
	return 0;
}


void Game::show_screen() {
	screen.show_background();
	screen.draw_entities(platforms, springs, enemies, doodle);
	screen.show_score(score);
	screen.update();
}

void Game::get_entities_from_file() {
	ifstream infile(MAP_NAME);
	int num_of_entities;
	Point p;
	string entity_type;
	infile >> num_of_entities;
	for (int i = 0 ; i < num_of_entities ; i ++) {
		infile >> p.x >> p.y >> entity_type;
		if (entity_type == "platform") {
			Static_Platform* new_static_platform = new Static_Platform(Point(p.x*COEFF, p.y*COEFF));
			platforms.push_back(new_static_platform);
			entities.push_back(new_static_platform);
		}
		else if (entity_type == "mplatform") {
			Moving_Platform* new_moving_platform = new Moving_Platform(Point(p.x*COEFF, p.y*COEFF));
			platforms.push_back(new_moving_platform);
			entities.push_back(new_moving_platform);
		}	
		else if (entity_type == "bplatform") {
			Breaking_Platform* new_breaking_platform = new Breaking_Platform(Point(p.x*COEFF, p.y*COEFF));
			platforms.push_back(new_breaking_platform);
			entities.push_back(new_breaking_platform);
		}
		else if (entity_type == "enemy") {
			Enemy* new_enemy = new Enemy(Point(p.x*COEFF, p.y*COEFF));
			enemies.push_back(new_enemy);
			entities.push_back(new_enemy);
		}
		else if (entity_type == "spring") {
			Spring* new_spring = new Spring(Point(p.x*COEFF, p.y*COEFF));
			springs.push_back(new_spring);
			entities.push_back(new_spring);
		}
	}
}

void Game::update_score(int diff) {
	if (doodle.get_y() > score)
		score = doodle.get_y();
	if (diff > 0)
		score +=diff;
}