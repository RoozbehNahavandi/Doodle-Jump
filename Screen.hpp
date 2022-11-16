
#include "Entity.hpp"
#include <vector>
#include "src/rsdl.hpp"
#include "Doodle.hpp"
#include "Enemy_Spring.hpp"
#include "Platform.hpp"


class Screen {
public:
	Screen();
	void draw_entities(vector<Platform*>, vector<Spring*>, vector<Enemy*>, Doodle&);
	void draw_platform(Platform*);
	void draw_spring(Spring*);
	void draw_enemy(Enemy*);
	void draw_entity(Entity*);
	void show_background();
	void update();
	Window* get_window();
	void draw_doodle(Doodle&);
	void show_score(int);
	void clear_screen();
	void game_over_text(int);
	void play_sound(std::string);
private:
	Window window;
	void break_animation(Platform*);
};