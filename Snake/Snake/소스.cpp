#include "Game.h"

#define BoundaryX = 40
#define BoundaryY = 40

Game game;

void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_UP:
		game.getSnake().setDir(up);
		break;
	case GLUT_KEY_DOWN:
		game.getSnake().setDir(down);
		break;
	case GLUT_KEY_LEFT:
		game.getSnake().setDir(left);
		break;
	case GLUT_KEY_RIGHT:
		game.getSnake().setDir(right);
		break;
	}
}

void renderScene(void) {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D();

	game.Run();

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	glutCreateWindow("Snake");

	glutDisplayFunc(renderScene);
	glutSpecialFunc(processSpecialKeys);
	
	glutMainLoop();

	return 0;
}