#pragma once
#include "Box.h"
#include <list>

enum direction { up = 0, down = 1, left = 2, right = 3 };

class Snake : public Box
{
public:
	Snake(); //dh
	void drawSnake();
	void moveSnake(); //yj

	void setDir(direction dir_);
	int getDir();
	std::list<Box> getBody();//isEat ������� snake�� body�� get�ؾߵ�.

private:
	std::list<Box> body;
	direction dir;
};

