#include "Game.h"

Game::Game() {
	genItem();
	Item.setColor(RED);
}

void Game::Run() {
	if (!isDie()) {
		if (isEat()) {
			Box tail(snake.getBody().back().getPosX(), snake.getBody().back().getPosY());
			snake.moveSnake();
			snake.getBody().push_back(tail);
			genItem();
		}
		else
			snake.moveSnake();
	}
	else
		Clear();
	draw();
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
	for (int i = 2; i < 41; i++){
		glVertex2f(1, i); glVertex2f(41, i);
		glVertex2f(i, 1); glVertex2f(i, 41);
	}
	glEnd();
	
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
	glVertex2f(1, 1); glVertex2f(41, 1);
	glVertex2f(1, 1); glVertex2f(1, 41);
	glVertex2f(1, 41); glVertex2f(41, 41);
	glVertex2f(41, 1); glVertex2f(41, 41);
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
			if (((*it).getPosX() == x) && ((*it).getPosY() == y)) {
				a = 1;
				break;
			}
		}
		if (a == 0) 
			break;
	}
	Item.setPos(x, y);
}

bool Game::isEat() {
	if (snake.getBody().front().getPosX() == Item.getPosX() && snake.getBody().front().getPosY() == Item.getPosY()) {
		if (snake.getMove() <= 400)
			snake.setMove(snake.getMove() + 100);
		else
			snake.setMove(500);
		return true;
	}
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
void Game::move(direction dir_) {
	switch (dir_) {
	case up:
		if (snake.getDir() != down) {
			snake.setDir(up);
			glutPostRedisplay();
		}
		break;
	case down:
		if (snake.getDir() != up) {
			snake.setDir(down);
			glutPostRedisplay();
		}
		break;
	case left:
		if (snake.getDir() != right) {
			snake.setDir(left);
			glutPostRedisplay();
		}
		break;
	case right:
		if (snake.getDir() != left) {
			snake.setDir(right);
			glutPostRedisplay();
		}
		break;
	}
}

Snake& Game::getSnake() {
	return snake;
}
