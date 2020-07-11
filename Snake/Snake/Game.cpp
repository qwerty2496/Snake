#include "Game.h"

Game::Game() {
	genItem();
	Item.setColor(RED);
	die = false;
}

void Game::Run() {
	checkDie();
	if(!die){
		if (isEat()) {
			Box tail(snake.getBody().back());
			snake.moveSnake();
			snake.getBody().push_back(tail);
			genItem();
		}
		else
			snake.moveSnake();
	}
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
		std::uniform_int_distribution<int> dis(0, 39);
		x = dis(gen);
		y = dis(gen);

		std::list<Box> SB = snake.getBody();
		std::list<Box>::iterator it = SB.begin();
		for (it; it != SB.end(); it++) {
			if ((*it).getPosX() == x && (*it).getPosY() == y) {
				int a = 1;
				break;
			}
		}
		if (a == 0) break;
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
	std::list<Box> SB = snake.getBody();
	std::list<Box>::iterator it = SB.begin();
	it++;

	if (hX == -1 || hX == 40 || hY == -1 || hY == 40) {
		die = true;
	}
	
	for (it; it != SB.end(); it++) {
		if ((*it).getPosX() == hX && (*it).getPosY() == hY) {
			die = true;
			break;
		}
	}
}

bool Game::getDie() {
	return die;
}
Snake Game::getSnake() {
	return snake;
}
