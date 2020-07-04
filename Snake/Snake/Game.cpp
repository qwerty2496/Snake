#include "Game.h"

Game::Game() {
	Item.setColor(RED);
	Item.setPos(0, 0);
}

void Game::genItem() {
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

void Game::draw() {
	Item.drawBox();
	snake.drawSnake();
}