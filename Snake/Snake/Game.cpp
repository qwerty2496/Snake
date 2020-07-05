#include "Game.h"

Game::Game() {
	Item.setColor(RED);
}

void Game::Run() {
	//�ؿ� ��Ʈ - Game�� �ٸ� ��� �Լ��� ����
	glutPostRedisplay();//��� ��������
}

void Game::draw() {
	Item.drawBox();
	snake.drawSnake();
}

void Game::genItem() {
	//�ؿ� ��Ʈ - ���� ��ǥ�� snake�� �Ӹ� �� ���� ��ǥ�� ��ġ�� �ʰ� �߰�
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 40);
	float x = dis(gen);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 40);
	float y = dis(gen);

	Item.setPos(x, y);
}

bool Game::isEat() {
	//���� ��Ʈ - �Ӹ� ��ǥ�� ���� ��ǥ�� ��Ĩ ����
	if (snake.getBody()[0].getPosX()==Item.getPosX() && snake.getBody()[0].getPosY()==Item.getPosY())
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Game::isDie() {
	/*���� ��Ʈ 
	1.�Ӹ��� ���뿡 �ε��� ����
		-snake�� �̵����� (dir) ����� ��
	2. �Ӹ��� ���� �ε��� ����
		-�� ������ ��ǥ: (0,0), (0,40), (40,40), (40,0)

		Ŭ���� ��� ���Ͽ� boundaryX, boundaryY�� �����ϸ� ���� �� ������
		�ҽ� ���Ͽ� ������ �Ͱ� �浹�ϴ��� �� �𸣰ڴ�
	*/
}

Snake Game::getSnake() {
	return snake;
}
