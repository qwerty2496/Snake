#pragma once
#include "Box.h"
#include "Snake.h"
#include <random>
#include <algorithm>

class Game
{
public:
	Game();

	void genItem(); 

	void Run();
	void draw();

	bool isEat(); 
	void checkDie();
	bool getDie();

	Snake getSnake();

private:
	Box Item;
	Snake snake;
	bool die;
};

