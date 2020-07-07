#include "Game.h"

Game::Game() {
	Item.setColor(RED);
}

void Game::Run() {
	//준영 파트 - Game의 다른 멤버 함수들 조합
	glutPostRedisplay();//요건 지우지마
}

void Game::draw() {
	Item.drawBox();
	snake.drawSnake();
}

void Game::genItem() {
	//준영 파트 - 먹이 좌표가 snake의 머리 및 몸통 좌표와 겹치기 않게 추가
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
	//유제 파트 - 머리 좌표와 먹이 좌표의 겹칩 여부
	if (snake.getBody().front().getPosX() == Item.getPosX() && snake.getBody().front().getPosY() == Item.getPosY())
		return true;
	else
		return false;
}
bool Game::isDie() {
	/*
		동헌 파트 
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
