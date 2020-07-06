#include "Snake.h"

Snake::Snake() {
	//동헌 파트-초기 길이 3, 초기 머리 좌표 (20, 20), 방향은 임의로 정하세요
}

std::list<Box> Snake::getBody() {
	return body;
}
void Snake::setDir(direction dir_) {
	dir = dir_;
}
int Snake::getDir() {
	return dir;
}

void Snake::drawSnake() {
	for (auto& box : body) {
		box.drawBox();
	}
}
void Snake::moveSnake() {
	/*
	 head생성/ 꼬리 없애기 반복
	*/
	float tempPosX = body.front().getPosX();
	float tempPosY = body.front().getPosY();
	if (dir == up)
		body.push_front(Box(tempPosX, tempPosY + 1));
	else if (dir == down)
		body.push_front(Box(tempPosX, tempPosY - 1));
	else if (dir == left)
		body.push_front(Box(tempPosX - 1, tempPosY));
	else
		body.push_front(Box(tempPosX + 1, tempPosY));
	body.pop_back();
}
