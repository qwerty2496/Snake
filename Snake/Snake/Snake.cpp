#include "Snake.h"

void Snake::drawSnake() {
	for (auto& box : body) {
		box.drawBox();
	}
}