#include "Platform.hpp"
#include "Screen.hpp"
#include <vector>
#include <fstream>
#include "Doodle.hpp"
#include "define.hpp"
#include "Enemy_Spring.hpp"




class Game {
private:
	Screen screen;
	vector<Entity*> entities;
	vector<Platform*> platforms;
	vector<Enemy*> enemies;
	vector<Spring*> springs;
	Doodle doodle;
	int score = 0;
	void get_entities_from_file();
	int keep_doodle_in_screen();
	void update_score(int);
	int lost(vector<Enemy*>);
	void lose_animation(int);
	void initialize_game();
public:
	void play_game();
	void show_screen();
	void update_screen();
	void update();
};