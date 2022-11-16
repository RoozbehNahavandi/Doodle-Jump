#include <iostream>
#include "src/rsdl.hpp"
#include <cmath>

using namespace std;

const int WIDTH = 640;
const int HEIGHT = 1024;
const double COEFF = 0.68;

class Platform {
public:
	Platform(int, int);
private:
	int x;
	int y;
};

Platform::Platform(int _x, int _y) : x(_x), y(_y) {}

void update(Window* window) {
	if (window->has_pending_event()) {
		Event e = window->poll_for_event();
		switch (e.get_type()) {
			case Event::EventType::QUIT:
			exit(0);
			break;
		}
	}
}

int main() {
	Window *window = new Window(WIDTH*COEFF, HEIGHT*COEFF, "Background");
	string filename = "assets/main pictures/background.png";
	window->draw_img( filename,  NULL_RECT, NULL_RECT, 0,false,false);
	string platform = "assets/main pictures/game-tiles.png";
	Rectangle rec1 = Rectangle(2, 3, 130, 30);
	Rectangle rec2 = Rectangle(2, 3, 130, 30);
	window->draw_img(platform,  rec1, rec2);


	while (true) {
		delay(15);
		window->update_screen();
		update(window);
	}
	
}