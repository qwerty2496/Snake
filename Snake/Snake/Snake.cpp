#include "Snake.h"

Snake::Snake(){
	body.push_back(Box(20, 20));
	body.push_back(Box(20, 19));
	body.push_back(Box(20, 18));
	body.front().setColor(GREEN);
	setDir(up);
}

std::list<Box>& Snake::getBody() {
	return body;
}
void Snake::setDir(direction dir_) {
	dir = dir_;
}
int Snake::getDir() {
	return dir;
} 

void Snake::drawSnake() {
	for (auto& box : body)
		box.drawBox();
}
void Snake::moveSnake() {
	float tempPosX = body.front().getPosX();
	float tempPosY = body.front().getPosY();
	body.front().setColor(WHITE);
	if (dir == up)
		body.push_front(Box(tempPosX, tempPosY + 1));
	else if (dir == down)
		body.push_front(Box(tempPosX, tempPosY - 1));
	else if (dir == left)
		body.push_front(Box(tempPosX - 1, tempPosY));
	else
		body.push_front(Box(tempPosX + 1, tempPosY));
	body.front().setColor(GREEN);
	body.pop_back();
}