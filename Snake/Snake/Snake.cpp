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
	//���� ��Ʈ
}

void Snake::setDir(direction dir_) {
	dir = dir_;
}
int Snake::getDir() {
	return dir;
}