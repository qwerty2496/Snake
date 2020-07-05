#include "Snake.h"

Snake::Snake() {
	//동헌 파트-초기 길이 3, 초기 머리 좌표 (20, 20), 방향은 임의로 정하세요
}

void Snake::drawSnake() {
	for (auto& box : body) {
		box.drawBox();
	}
}
void Snake::moveSnake() {
	//유제 파트
}

void Snake::setDir(direction dir_) {
	dir = dir_;
}
int Snake::getDir() {
	return dir;
}