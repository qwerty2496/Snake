#include "Snake.h"

Snake::Snake() {
	
	body.push_back(Box(20.0, 20.0));
	body.push_back(Box(20.0, 19.0));
	body.push_back(Box(20.0, 18.0));
	setDir(up);
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
/*
void Snake::incSnake() {
	float hX1 = body.back().getPosX();
	float hY1 = body.back().getPosY();
	std::list<Box>::iterator it = body.end();
	it--;
	float hX2 = (*it).getPosX();
	float hY2 = (*it).getPosY();

	if (hY2 - hY1 == -1)
		body.push_back(Box(hX1, hY1 + 1));
	else if (hY2 - hY1 == 1)
		body.push_back(Box(hX1, hY1 - 1));
	else if (hX2 - hX1 == 1)
		body.push_back(Box(hX1 - 1, hY1));
	else
		body.push_back(Box(hX1 + 1, hY1));
}*/
