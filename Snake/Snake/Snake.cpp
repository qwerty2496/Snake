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
	/*
	head의 좌표만 직접 바꿔주고 나머지는 앞 박스의 위치를 받는다.
	*/
	int nowDir = getDir();
	float tempPosX_a = body[0].getPosX();
	float tempPosY_a = body[0].getPosY();
	if (nowDir == up)
	{
		body[0].setPos(body[0].getPosX(), body[0].getPosY() + 1);
	}
	else if (nowDir== down) {
		body[0].setPos(body[0].getPosX(), body[0].getPosY() - 1);
	}
	else if (nowDir== left)
	{
		body[0].setPos(body[0].getPosX()-1, body[0].getPosY());
	}
	else
	{
		body[0].setPos(body[0].getPosX()+1, body[0].getPosY());
	}
	for (int i = 1; i < body.size(); i++)
	{
		float tempPosX_b = body[i].getPosX();
		float tempPosY_b = body[i].getPosY();
		body[i].setPos(tempPosX_a, tempPosY_a);
		tempPosX_a = tempPosX_b;
		tempPosY_a = tempPosY_b;

	}
	/*
	 head생성/ 꼬리 없애기 반복
	*/
	/*
	int nowDir = getDir();
	float tempPosX = body[0].getPosX();
	float tempPosY = body[0].getPosY();
	if (nowDir==up)
	{
		body.insert(body.begin(), Box(tempPosX, tempPosY + 1));
	}
	else if (nowDir == down)
	{
		body.insert(body.begin(), Box(tempPosX, tempPosY - 1));
	}
	else if (nowDir == left)
	{
		body.insert(body.begin(), Box(tempPosX-1, tempPosY));
	}
	else
	{
		body.insert(body.begin(), Box(tempPosX+1, tempPosY));
	}
	body.pop_back();

	*/
	}
std::vector<Box> Snake::getBody() {
	return body;
}
void Snake::setDir(direction dir_) {
	dir = dir_;
}
int Snake::getDir() {
	return dir;
}