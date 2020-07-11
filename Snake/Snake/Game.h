#pragma once
#include <random>
#include <algorithm>
#include <time.h>
#include "Box.h"
#include "Snake.h"


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

