#include "Game.h"

Game::Game() {
	genItem();
	Item.setColor(RED);
}

void Game::Run() {
	draw();
	if (!isDie()) {
		if (isEat()) {
			Box tail(snake.getBody().back().getPosX(), snake.getBody().back().getPosX());
			snake.moveSnake();
			snake.getBody().push_back(tail);
			genItem();
		}
		else
			snake.moveSnake();
	}
	else
		Clear();
}
void Game::Clear() {
	Snake newSnake;
	snake = newSnake;
	genItem();
}
void Game::draw(){
	Item.drawBox();
	snake.drawSnake();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);

	for (int i = 1; i < 42; i++){
		glVertex2f(1, i); glVertex2f(41, i);
		glVertex2f(i, 1); glVertex2f(i, 41);
	}
	glEnd();
}

void Game::genItem() {
	float x;
	float y;
	while (true) {
		int a = 0;
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dis(1, 40);
		x = dis(gen);
		y = dis(gen);

		std::list<Box>::iterator it = snake.getBody().begin();
		for (it; it != snake.getBody().end(); it++) {
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

bool Game::isDie() {
	float hX = snake.getBody().front().getPosX();
	float hY = snake.getBody().front().getPosY();
	std::list<Box>::iterator it = snake.getBody().begin();
	it++;

	if (hX == 0 || hX == 41 || hY == 0 || hY == 41) {
		return true;
	}
	for (it; it != snake.getBody().end(); it++) {
		if ((*it).getPosX() == hX && (*it).getPosY() == hY) {
			return true;
		}
	}
	return false;
}

Snake& Game::getSnake() {
	return snake;
}
