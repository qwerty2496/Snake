#pragma once
#include <iostream>
#include <GL/glut.h>

enum Color{WHITE = 0, RED = 1};

class Box
{
public:
	Box();
	Box(float x, float y);

	void drawBox() const;

	void setColor(Color col);

	void setPos(const float x, const float y);
	float getPosX();
	float getPosY();

private:
	float pos[2];
	Color color;
};

