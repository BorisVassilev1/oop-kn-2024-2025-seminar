#include <iostream>

enum Color : int {
	RED,
	GREEN,
	BLUE,
	CYAN,
	MAGENTA,
	YELLOW,
	PINK,
	PURPLE,
	COLOR_COUNT
};

int main() {
	Color c = Color::RED + Color::BLUE;

	for(int i = 0; i < Color::COLOR_COUNT; ++i) {
		Color c = static_cast<Color>(i);

	}


}
