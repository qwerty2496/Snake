#include "Game.h"

const int BoundaryX = 42;
const int BoundaryY = 42;

Game game;

void renderScene(void) {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, BoundaryX, 0, BoundaryY);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game.Run();
	
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(720, 720);
	glutCreateWindow("Snake");

	//callback
	glutDisplayFunc(renderScene);
	
	glutMainLoop();
	
	return 0;
}