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
	if (snake.getBody().front().getPosX() == Item.getPosX() && snake.getBody().front().getPosY() == Item.getPosY())
		return true;
	else
		return false;
}
bool Game::isDie() {
	/*
		���� ��Ʈ 
	*/
	
	float hX = body.front().getPosX();
	float hY = body.front().getPosY();
	std::list<Box>::iterator it = body.begin();
	it++;

	if (hX == 0 || hX == 40 || hY == 0 || hY == 40) return true;

	for (it; it != body.end(); it++)
		if ((*it).getPosX == hX && (*it).getPosY == hY) return true;
	
	return false;
	
}

Snake Game::getSnake() {
	return snake;
}
