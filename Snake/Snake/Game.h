#pragma once
#include "Box.h"
#include "Snake.h"
#include <ctime>
#include <cstdlib>
#include <random>
#include <algorithm>

class Game
{
public:
	Game();

	void genItem(); 

	bool Run();
	void draw();

	bool isEat(); 
	void checkDie();
	bool isDie() { return die; }

	Snake getSnake();

private:
	Box Item;
	Snake snake;
	bool die;
};

