#include "Game.h"

Game::Game() {
	Item.setColor(RED);
	die = false;
	genItem();
}

bool Game::Run() {
	checkDie();
	if (isDie()) return false;
	if (isEat()) {
		genItem();
		snake.incSnake();
	}
	draw();
	snake.moveSnake();
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
		srand(time(0));
		int a = 0;
		x = rand() % 40;
		y = rand() % 40;
		std::list<Box> bod = snake.getBody();
		std::list<Box>::iterator it = bod.begin();
		for (it; it != bod.end(); ++it) {
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
	std::list<Box> bd = snake.getBody();
	std::list<Box>::iterator it = bd.begin();
	it++;

	if (hX == 0 || hX == 40 || hY == 0 || hY == 40) {
		die = true;
		return;
	}

	for (it; it != bd.end(); ++it) {
		if ((*it).getPosX() == hX && (*it).getPosY() == hY) {
			die = true;
			return;
		}
	}
}

Snake Game::getSnake() {
	return snake;
}
