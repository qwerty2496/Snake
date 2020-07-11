#include "Game.h"

Game::Game() {
	Item.setColor(RED);
	Snake();
	die = false;
}

bool Game::Run() {
	checkDie();
	if (isDie()) return false;
	if (isEat()) {
		genItem();
		getSnake().incSnake();
	}
	draw();
	glutPostRedisplay();
	getSnake().moveSnake();
	return true;
}

void Game::draw() {
	Item.drawBox();
	snake.drawSnake();
}

void Game::genItem() {
	
	float x;
	float y;
	while (true) {
		int a = 0;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 40);
		x = dis(gen);

		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(0, 40);
		y = dis(gen);

		std::list<Box>::iterator it = snake.getBody().begin();
		for (it; it != snake.getBody().end(); it++) {
			if ((*it).getPosX() == x && (*it).getPosY() == y) {
				int a = 1;
				break;
			}
		}
		if (a != 1) break;
	}
	Item.setPos(x, y);
}

bool Game::isEat() {
	
	if (snake.getBody().front().getPosX() == Item.getPosX() && snake.getBody().front().getPosY() == Item.getPosY())
		return true;
	else
		return false;
}
void Game::checkDie() {
	
	
	float hX = snake.getBody().front().getPosX();
	float hY = snake.getBody().front().getPosY();
	std::list<Box>::iterator it = snake.getBody().begin();
	it++;

	if (hX == 0 || hX == 40 || hY == 0 || hY == 40) {
		die = true;
		return;
	}

	for (it; it != snake.getBody().end(); it++)
		if ((*it).getPosX() == hX && (*it).getPosY() == hY) {
			die = true;
			return;
		}
}

Snake Game::getSnake() {
	return snake;
}
