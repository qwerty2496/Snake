#pragma once
#include <random>
#include <algorithm>
#include "Box.h"
#include "Snake.h"


class Game
{
public:
	Game();

	void genItem(); 

	void Run();
	void Clear();
	void draw();

	bool isEat(); 
	bool isDie();
	void move(direction dir_);

	Snake& getSnake();

private:
	Box Item;
	Snake snake;
};

