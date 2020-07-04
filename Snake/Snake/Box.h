#pragma once
#include <GL/glut.h>
#include <iostream>

class Box
{
public:
	Box();
	Box(float x, float y);

	void drawBox() const;

	void setColor(int col);

	void setPos(const float x, const float y);
	float getPosX();
	float getPosY();

private:
	float pos[2];
	int color;
};

