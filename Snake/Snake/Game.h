#pragma once
#include "Box.h"
#include "Snake.h"
#include <random>
#include <algorithm>

class Game
{
public:
	Game();

	void genItem(); //jy

	void Run(); //jy
	void draw();

	bool isEat(); //yj
	bool isDie(); //dh

	Snake getSnake();

private:
	Box Item;
	Snake snake;
};

