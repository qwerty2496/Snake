#include "Snake.h"

Snake::Snake() {
	//���� ��Ʈ-�ʱ� ���� 3, �ʱ� �Ӹ� ��ǥ (20, 20), ������ ���Ƿ� ���ϼ���
}

void Snake::drawSnake() {
	for (auto& box : body) {
		box.drawBox();
	}
}
void Snake::moveSnake() {
	/*
	head�� ��ǥ�� ���� �ٲ��ְ� �������� �� �ڽ��� ��ġ�� �޴´�.
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
	 head����/ ���� ���ֱ� �ݺ�
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