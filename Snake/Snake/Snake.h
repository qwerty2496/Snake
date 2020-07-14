#pragma once
#include <list>
#include "Box.h"

enum direction{ up = 0, down = 1, left = 2, right = 3};

class Snake : public Box
{
public:
	Snake();
	void drawSnake();
	void moveSnake(); 
	void setDir(direction dir_);
	int getDir();
	std::list<Box> getBody();

private:
	std::list<Box> body;
	direction dir;
};

