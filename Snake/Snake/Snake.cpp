#include "Snake.h"

Snake::Snake() {
	//���� ��Ʈ-�ʱ� ���� 3, �ʱ� �Ӹ� ��ǥ (20, 20), ������ ���Ƿ� ���ϼ���
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
	/*
	 head����/ ���� ���ֱ� �ݺ�
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
